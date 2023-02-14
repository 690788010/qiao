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
	// ��ʼ������LinkAutoUniform������֮���Զ�������ɫ���ж�ӦUniform��ֵ
	int _numberOfTextureUnits;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &_numberOfTextureUnits);
	for (int i = 0; i < _numberOfTextureUnits; i++) {
		TextureUniform* textureUniform = new TextureUniform(i);
		_linkAutoUniforms.insert(std::pair<std::string, LinkAutoUniform*>(textureUniform->getName(), textureUniform));
	}

	// ��ʼ������DrawAutoUniformFactory������֮���Զ�������ɫ���ж�ӦUniform��ֵ
	ModelMatrixUniformFactory* modelMatrixUniformFactory = new ModelMatrixUniformFactory();
	_drawAutoUniformFactories.insert(
		std::pair<std::string, DrawAutoUniformFactory*>(modelMatrixUniformFactory->getName(), modelMatrixUniformFactory));

	// ������ɫ�����󣨱�����ɫ��Դ�룩
	ShaderObject _vertexShader(ShaderType::VERTEX_SHADER, vs);
	ShaderObject _fragmentShader(ShaderType::FRAGMENT_SHADER, fs);

	// �����������
	_program = glCreateProgram();

	// Ϊ����������ɫ������
	glAttachShader(_program, _vertexShader.handle());
	glAttachShader(_program, _fragmentShader.handle());
	// ����
	glLinkProgram(_program);

	// ����ʧ�����׳��쳣
	int success;
	char infoLog[512];
	glGetProgramiv(_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_program, 512, NULL, infoLog);
		throw std::invalid_argument("Could not link shader program.  Link Log:  \n" + std::string(infoLog));
	}

	// ��������ɫ�����ÿ�������attribute������Ԫ���ݱ�������
	_vertexAttributes = _findVertexAttributes(_program);

	// ����ɫ����Uniform������Ԫ���ݱ�������
	_uniforms = _findUniforms(_program);

	// ��ʼ��AutoUniform
	initAutoUniforms(_uniforms);
}

ShaderProgram::~ShaderProgram() {
	std::cout << "~ShaderProgram" << std::endl;

	if (_program != 0) {
		glDeleteProgram(_program);
		_program = 0;
	}

	// �ͷ�vector�ڸ���Ԫ�ص���Դ
	for (auto it : _vertexAttributes) {
		delete it.second;
	}

	// �ͷ�UniformCollection�ڸ���Ԫ�ص���Դ
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
	// ͨ��DrawAutoUniformCollection�б���ĸ���DrawAutoUniformΪ������Ӧ��Uniform�Զ�����ֵ
	setDrawAutoUniforms(context, drawState, sceneState);

	// ͨ�����ø���Uniform��clean()��������ֵ���͵�GPU
	for (ICleanable* cleaner : _dirtyUniforms) {
		cleaner->clean();
	}

	// ���_dirtyUniforms
	_dirtyUniforms.clear();
};

ShaderVertexAttributeCollection ShaderProgram::vertexAttributes() {
	return _vertexAttributes;
};

UniformCollection ShaderProgram::uniforms() {
	return _uniforms;
};

// ʹ�ñ���������ƬԪ��ɫ��out����������λ��
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
	// ������ɫ���м���Attribute����������
	int numberOfAttributes;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &numberOfAttributes);
	// ������ɫ���м���Attribute����������󳤶�
	int attributeNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &attributeNameMaxLength);

	ShaderVertexAttributeCollection vertexAttributes;
	for (int i = 0; i < numberOfAttributes; i++) {
		int attributeNameLength;		// ������ʵ�ʳ���
		int attributeSize;				// ����ռ���ֽ�����
		GLenum attributeType;			// ��������
		char* attributeName = new char[attributeNameMaxLength];
		glGetActiveAttrib(program, i, attributeNameMaxLength, &attributeNameLength,
			&attributeSize, &attributeType, attributeName);

		// �����������"gl_"��ͷ��������
		if (strcmp(attributeName, "gl_") == 0) {
			continue;
		};

		// ��ȡ��������λ��
		int attributeLocation = glGetAttribLocation(program, attributeName);
		// ����ñ�����ص�Ԫ����
		vertexAttributes.insert(std::pair<std::string, ShaderVertexAttribute*>(
			attributeName, 
			new ShaderVertexAttribute(attributeName, attributeLocation, attributeType, attributeSize)));
	}
	return vertexAttributes;
};

UniformCollection ShaderProgram::_findUniforms(GLuint program) {
	// ��ȡ��ɫ���м����Uniform�����ĸ���
	int numberOfUniforms;
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numberOfUniforms);

	// ��ȡ�����Uniform�����ı���������󳤶�
	int uniformNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniformNameMaxLength);

	UniformCollection uniforms;
	for (int i = 0; i < numberOfUniforms; i++) {
		int uniformNameLength;		// uniform�������ĳ���
		int uniformSize;			// uniform����ռ���ֽ�����
		GLenum uniformType;			// uniform����������
		char* uniformName = new char[uniformNameMaxLength];
		glGetActiveUniform(program, i, uniformNameMaxLength, &uniformNameLength,
			&uniformSize, &uniformType, uniformName);
		
		// ���Uniform��������"gl_"��ͷ��������
		if (strcmp(uniformName, "gl_") == 0) {
			continue;
		}

		// �����Uniform������ص�Ԫ����
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
			// Ϊ��LinkAutoUniform��Ӧ��Uniform�Զ�����ֵ
			_linkAutoUniforms[name]->set(uniform);
		}
		else if (_drawAutoUniformFactories.find(name) != _drawAutoUniformFactories.end()) {
			// ΪUniform������Ӧ��DrawAutoUniform��������DrawAutoUniformCollection��
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