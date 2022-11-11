
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

	// ���ڲ���ƬԪ��ɫ��out����������λ��
	_fragmentOutputs = FragmentOutputsGL3x(_program);
	// Ϊ������ɫ�����ÿ�������attribute��������Ԫ����
	_vertexAttributes = findVertexAttributes(_program);
	_uniforms = findUniforms(_program);

	// ��ʼ��AutoUniform
	initAutoUniforms(_uniforms);
};

ShaderProgramGL3x::~ShaderProgramGL3x() {
	std::cout << "~ShaderProgramGL3x" << std::endl;
	if (_program != 0) {
		glDeleteProgram(_program);
		_program = 0;
	}

	// �ͷ�vector�ڸ���Ԫ�ص���Դ
	for (size_t i = 0; i < _vertexAttributes.size(); i++) {
		delete _vertexAttributes[i];
	}

	// �ͷ�UniformCollection�ڸ���Ԫ�ص���Դ
	std::map<std::string, Uniform*>::iterator it = _uniforms.begin();
	while (it != _uniforms.end()) {
		delete it->second;
		it++;
	}
}

void ShaderProgramGL3x::use() {
	glUseProgram(_program);
}

void ShaderProgramGL3x::clean(Context* context, DrawState* drawState, SceneState* sceneState) {
	// ͨ��DrawAutoUniformCollection�б���ĸ���DrawAutoUniformΪ������Ӧ��Uniform�Զ�����ֵ
	setDrawAutoUniforms(context, drawState, sceneState);
	
	// ʹ��GL���ý�Uniformֵ���͵�GPU
	std::list<ICleanable*>::iterator it = _dirtyUniforms.begin();
	while (it != _dirtyUniforms.end()) {
		(*it)->clean();
		it++;
	}
	_dirtyUniforms.clear();
};

ShaderVertexAttributeCollection ShaderProgramGL3x::vertexAttributes() {
	return _vertexAttributes;
};

UniformCollection& ShaderProgramGL3x::uniforms() {
	return _uniforms;
};

void ShaderProgramGL3x::notifyDirty(ICleanable* val) {
	_dirtyUniforms.push_back(val);
};

ShaderVertexAttributeCollection ShaderProgramGL3x::findVertexAttributes(GLuint program) {
	int numberOfAttributes;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &numberOfAttributes);

	int attributeNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &attributeNameMaxLength);

	ShaderVertexAttributeCollection vertexAttributes;
	for (int i = 0; i < numberOfAttributes; i++) {
		int attributeNameLength;
		int attributeSize;
		GLenum attributeType;
		char* attributeName = new char[attributeNameMaxLength];
		glGetActiveAttrib(program, i, attributeNameMaxLength, &attributeNameLength, 
			&attributeSize, &attributeType, attributeName);

		if (strcmp(attributeName, "gl_") == 0) {
			continue;
		};

		int attributeLocation = glGetAttribLocation(program, attributeName);
		vertexAttributes.push_back(new ShaderVertexAttribute(attributeName, attributeLocation, 
			attributeType, attributeSize));
	}
	return vertexAttributes;
};

UniformCollection ShaderProgramGL3x::findUniforms(GLuint program) {
	// ��ȡ�����Uniform�����ĸ���
	int numberOfUniforms;
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numberOfUniforms);
	
	// ��ȡ�����Uniform�����ı���������󳤶�
	int uniformNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniformNameMaxLength);
	
	UniformCollection uniforms;
	for (int i = 0; i < numberOfUniforms; i++) {
		int uniformNameLength;		// uniform�������ĳ���
		int uniformSize;			// 
		GLenum uniformType;			// uniform����������
		char* uniformName = new char[uniformNameMaxLength];
		glGetActiveUniform(program, i, uniformNameMaxLength, &uniformNameLength,
			&uniformSize, &uniformType, uniformName);

		if (strcmp(uniformName, "gl_") == 0) {
			continue;
		}

		int uniformLocation = glGetUniformLocation(program, uniformName);
		uniforms.insert(std::pair<std::string, Uniform*>(uniformName, createUniform(uniformName, uniformLocation, uniformType)));
	}

	return uniforms;
};

Uniform* ShaderProgramGL3x::createUniform(std::string name, int location, GLenum type) {
	switch (type) {
		case GL_INT:
			return new UniformIntGL3x(name, location, type, this);
		case GL_FLOAT:
			return new UniformFloatGL3x(name, location, type, this);
	}
	throw std::invalid_argument("An implementation for argument uniform type does not exist.");
};