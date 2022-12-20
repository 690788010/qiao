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

	ShaderObject _vertexShader(ShaderType::VERTEX_SHADER, vs);
	ShaderObject _fragmentShader(ShaderType::FRAGMENT_SHADER, fs);

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
	_fragmentOutputs = new FragmentOutputs(_program);
	// Ϊ������ɫ�����ÿ�������attribute��������Ԫ����
	_vertexAttributes = findVertexAttributes(_program);
	_uniforms = findUniforms(_program);

	// ��ʼ��AutoUniform
	initAutoUniforms(_uniforms);
}

ShaderProgram::~ShaderProgram() {
	std::cout << "~ShaderProgram" << std::endl;

	if (_program != 0) {
		glDeleteProgram(_program);
		_program = 0;
	}

	if (_fragmentOutputs != nullptr) {
		delete _fragmentOutputs;
		_fragmentOutputs = nullptr;
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

	// ʹ��GL���ý�Uniformֵ���͵�GPU
	std::list<ICleanable*>::iterator it = _dirtyUniforms.begin();
	while (it != _dirtyUniforms.end()) {
		(*it)->clean();
		it++;
	}
	_dirtyUniforms.clear();
};

ShaderVertexAttributeCollection ShaderProgram::vertexAttributes() {
	return _vertexAttributes;
};

UniformCollection& ShaderProgram::uniforms() {
	return _uniforms;
};

void ShaderProgram::notifyDirty(ICleanable* val) {
	_dirtyUniforms.push_back(val);
};

ShaderVertexAttributeCollection ShaderProgram::findVertexAttributes(GLuint program) {
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
		vertexAttributes.insert(std::pair<std::string, ShaderVertexAttribute*>(
			attributeName, 
			new ShaderVertexAttribute(attributeName, attributeLocation, attributeType, attributeSize)));
	}
	return vertexAttributes;
};

UniformCollection ShaderProgram::findUniforms(GLuint program) {
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

Uniform* ShaderProgram::createUniform(std::string name, int location, GLenum type) {
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