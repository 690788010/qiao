
#include <iostream>
#include <stdexcept>
#include <string>
#include "shader_program_gl3x.h"

using namespace qiao;

ShaderProgramGL3x::ShaderProgramGL3x(std::string vs, std::string fs) {
	ShaderObjectGL3x _vertexShader(ShaderType::VERTEX_SHADER, vs);
	ShaderObjectGL3x _fragmentShader(ShaderType::FRAGMENT_SHADER, fs);

	std::cout << "ShaderProgramGL3x" << std::endl;
	_program = glCreateProgram();

	glAttachShader(_program, _vertexShader.handle());
	glAttachShader(_program, _fragmentShader.handle());
	glLinkProgram(_program);
	int success;
	char infoLog[512];
	glGetProgramiv(_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_program, 512, NULL, infoLog);
		std::cout << std::string(infoLog) << std::endl;
		throw std::invalid_argument("Could not link shader program.  Link Log:  \n" + std::string(infoLog));
	}

	// 用于查找片元着色器out变量的索引位置
	_fragmentOutputs = FragmentOutputsGL3x(_program);
	// 为顶点着色器里的每个激活的attribute变量构建元数据
	_vertexAttributes = findVertexAttributes(_program);
};

ShaderProgramGL3x::~ShaderProgramGL3x() {
	std::cout << "~ShaderProgramGL3x" << std::endl;
	if (_program != 0) {
		glDeleteProgram(_program);
		_program = 0;
	}

	// 释放vector内各个元素的资源
	for (size_t i = 0; i < _vertexAttributes.size(); i++) {
		delete _vertexAttributes[i];
	}
}

void ShaderProgramGL3x::use() {
	glUseProgram(_program);
}

ShaderVertexAttributeCollection ShaderProgramGL3x::vertexAttributes() {
	return _vertexAttributes;
};

ShaderVertexAttributeCollection ShaderProgramGL3x::findVertexAttributes(GLuint program) {
	int numberOfAttributes;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &numberOfAttributes);

	int attributeNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &attributeNameMaxLength);

	ShaderVertexAttributeCollection vertexAttributes;
	for (int i = 0; i < numberOfAttributes; i++) {
		int attributeNameLength;
		int attributeLength;
		GLenum attributeType;
		char* attributeName = new char[attributeNameMaxLength];
		glGetActiveAttrib(program, i, attributeNameMaxLength, &attributeNameLength, &attributeLength, &attributeType, attributeName);

		if (strcmp(attributeName, "gl_") == 0) {
			continue;
		};

		int attributeLocation = glGetAttribLocation(program, attributeName);
		vertexAttributes.push_back(new ShaderVertexAttribute(attributeName, attributeLocation, attributeType, attributeLength));
	}
	return vertexAttributes;
};