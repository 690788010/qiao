/*****************************************************************//**
 * \file   shader_program.cc
 * \brief  
 * 
 * \author DELL
 * \date   December 2022
 *********************************************************************/

#include <iostream>
#include "shader_program.h"

using namespace qiao;

ShaderProgram::ShaderProgram(std::string vs, std::string fs) {
	// 初始化各个LinkAutoUniform，用于之后自动设置着色器中对应Uniform的值
	int _numberOfTextureUnits;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &_numberOfTextureUnits);
	for (int i = 0; i < _numberOfTextureUnits; i++) {
		TextureUniform* textureUniform = new TextureUniform(i);
		_linkAutoUniforms.insert(std::pair<std::string, LinkAutoUniform*>(textureUniform->getName(), textureUniform));
	}

	// 初始化各个DrawAutoUniformFactory，用于之后自动设置着色器中对应Uniform的值
	ModelMatrixUniformFactory* modelMatrixUniformFactory = new ModelMatrixUniformFactory();
	_drawAutoUniformFactories.insert(
		std::pair<std::string, DrawAutoUniformFactory*>(modelMatrixUniformFactory->getName(), modelMatrixUniformFactory));

	// 创建着色器对象（编译着色器源码）
	ShaderObject _vertexShader(ShaderType::VERTEX_SHADER, vs);
	ShaderObject _fragmentShader(ShaderType::FRAGMENT_SHADER, fs);

	// 创建程序对象
	_program = glCreateProgram();

	// 为程序对象绑定着色器对象
	glAttachShader(_program, _vertexShader.handle());
	glAttachShader(_program, _fragmentShader.handle());
	// 链接
	glLinkProgram(_program);

	// 链接失败则抛出异常
	int success;
	char infoLog[512];
	glGetProgramiv(_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_program, 512, NULL, infoLog);
		throw std::invalid_argument("Could not link shader program.  Link Log:  \n" + std::string(infoLog));
	}

	// 将顶点着色器里的每个激活的attribute变量的元数据保存下来
	_vertexAttributes = _findVertexAttributes(_program);

	// 将着色器里Uniform变量的元数据保存下来
	_uniforms = _findUniforms(_program);

	// 初始化AutoUniform
	initAutoUniforms(_uniforms);
}

ShaderProgram::~ShaderProgram() {
	std::cout << "~ShaderProgram" << std::endl;

	if (_program != 0) {
		glDeleteProgram(_program);
		_program = 0;
	}

	// 释放vector内各个元素的资源
	for (auto it : _vertexAttributes) {
		delete it.second;
	}

	// 释放UniformCollection内各个元素的资源
	std::map<std::string, Uniform*>::iterator it = _uniforms.begin();
	while (it != _uniforms.end()) {
		delete it->second;
		it->second = nullptr;
		it++;
	}
}

void ShaderProgram::use() {
	glUseProgram(_program);
}

void ShaderProgram::clean(Context* context, DrawState* drawState, SceneState* sceneState) {
	// 通过DrawAutoUniformCollection中保存的各个DrawAutoUniform为各个对应的Uniform自动设置值
	setDrawAutoUniforms(context, drawState, sceneState);

	// 通过调用各个Uniform的clean()方法将新值传送到GPU
	for (ICleanable* cleaner : _dirtyUniforms) {
		cleaner->clean();
	}

	// 清空_dirtyUniforms
	_dirtyUniforms.clear();
};

ShaderVertexAttributeCollection ShaderProgram::vertexAttributes() {
	return _vertexAttributes;
};

UniformCollection ShaderProgram::uniforms() {
	return _uniforms;
};

// 使用变量名查找片元着色器out变量的索引位置
GLint ShaderProgram::getFragLocByName(std::string name) {
	GLint i = glGetFragDataLocation(_program, name.c_str());

	if (i == -1) {
		throw std::invalid_argument(
			"the argument is not the name of an active user-defined varying out fragment shader variable within program!");
	}

	return i;
};

void ShaderProgram::notifyDirty(ICleanable* val) {
	_dirtyUniforms.push_back(val);
};

ShaderVertexAttributeCollection ShaderProgram::_findVertexAttributes(GLuint program) {
	// 顶点着色器中激活Attribute变量的数量
	int numberOfAttributes;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &numberOfAttributes);
	// 顶点着色器中激活Attribute变量名的最大长度
	int attributeNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &attributeNameMaxLength);

	ShaderVertexAttributeCollection vertexAttributes;
	for (int i = 0; i < numberOfAttributes; i++) {
		int attributeNameLength;		// 变量名实际长度
		int attributeSize;				// 变量占用字节数量
		GLenum attributeType;			// 变量类型
		char* attributeName = new char[attributeNameMaxLength];
		glGetActiveAttrib(program, i, attributeNameMaxLength, &attributeNameLength,
			&attributeSize, &attributeType, attributeName);

		// 如果变量名以"gl_"开头，则跳过
		if (strcmp(attributeName, "gl_") == 0) {
			continue;
		};

		// 获取变量索引位置
		int attributeLocation = glGetAttribLocation(program, attributeName);
		// 保存该变量相关的元数据
		vertexAttributes.insert(std::pair<std::string, ShaderVertexAttribute*>(
			attributeName, 
			new ShaderVertexAttribute(attributeName, attributeLocation, attributeType, attributeSize)));
	}
	return vertexAttributes;
};

UniformCollection ShaderProgram::_findUniforms(GLuint program) {
	// 获取着色器中激活的Uniform变量的个数
	int numberOfUniforms;
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numberOfUniforms);

	// 获取激活的Uniform变量的变量名的最大长度
	int uniformNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniformNameMaxLength);

	UniformCollection uniforms;
	for (int i = 0; i < numberOfUniforms; i++) {
		int uniformNameLength;		// uniform变量名的长度
		int uniformSize;			// uniform变量占用字节数量
		GLenum uniformType;			// uniform变量的类型
		char* uniformName = new char[uniformNameMaxLength];
		glGetActiveUniform(program, i, uniformNameMaxLength, &uniformNameLength,
			&uniformSize, &uniformType, uniformName);
		
		// 如果Uniform变量名以"gl_"开头，则跳过
		if (strcmp(uniformName, "gl_") == 0) {
			continue;
		}

		// 保存该Uniform变量相关的元数据
		int uniformLocation = glGetUniformLocation(program, uniformName);
		uniforms.insert(std::pair<std::string, Uniform*>(uniformName, _createUniform(uniformName, uniformLocation, uniformType)));
	}

	return uniforms;
};

Uniform* ShaderProgram::_createUniform(std::string name, int location, GLenum type) {
	switch (type) {
		case GL_INT:
		case GL_SAMPLER_2D:
			return new UniformInt(name, location, type, this);
		case GL_FLOAT:
			return new UniformFloat(name, location, type, this);
		case GL_FLOAT_MAT4:
			return new UniformMatrix4D(name, location, type, this);
	}
	throw std::invalid_argument("An implementation for argument uniform type does not exist.");
};


void ShaderProgram::initAutoUniforms(UniformCollection uniforms) {
	for (std::map<std::string, Uniform*>::iterator it = uniforms.begin(); it != uniforms.end(); it++) {
		std::string name = it->first;
		Uniform* uniform = it->second;
		if (_linkAutoUniforms.find(name) != _linkAutoUniforms.end()) {
			// 为与LinkAutoUniform对应的Uniform自动设置值
			_linkAutoUniforms[name]->set(uniform);
		}
		else if (_drawAutoUniformFactories.find(name) != _drawAutoUniformFactories.end()) {
			// 为Uniform创建对应的DrawAutoUniform并保存在DrawAutoUniformCollection中
			DrawAutoUniform* drawAutoUniform = _drawAutoUniformFactories[name]->create(uniform);
			_drawAutoUniforms.push_back(drawAutoUniform);
		}
	}
};

void ShaderProgram::setDrawAutoUniforms(Context* context, DrawState* drawState, SceneState* sceneState) {
	for (auto& autoUniform : _drawAutoUniforms) {
		autoUniform->set(context, drawState, sceneState);
	}
};