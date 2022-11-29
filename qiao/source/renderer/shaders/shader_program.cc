
#include <iostream>
#include "shader_program.h"

using namespace qiao;

ShaderProgram::ShaderProgram(std::string vs, std::string fs) {
	std::cout << "ShaderProgram" << std::endl;
	
	// 初始化各个LinkAutoUniform，用于之后自动设置着色器中对应Uniform的值
	int _numberOfTextureUnits;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &_numberOfTextureUnits);
	for (int i = 0; i < _numberOfTextureUnits; i++) {
		_linkAutoUniforms.insert(std::pair<std::string, LinkAutoUniform*>("og_texture" + i, new TextureUniform(i)));
	}

	// 初始化各个DrawAutoUniform，用于之后自动设置着色器中对应Uniform的值
	_drawAutoUniformFactories.insert(
		std::pair<std::string, DrawAutoUniformFactory*>("og_modelMatrix", new ModelMatrixUniformFactory()));

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

	// 用于查找片元着色器out变量的索引位置
	_fragmentOutputs = new FragmentOutputs(_program);
	// 为顶点着色器里的每个激活的attribute变量构建元数据
	_vertexAttributes = findVertexAttributes(_program);
	_uniforms = findUniforms(_program);

	// 初始化AutoUniform
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

	// 释放vector内各个元素的资源
	for (size_t i = 0; i < _vertexAttributes.size(); i++) {
		delete _vertexAttributes[i];
	}

	// 释放UniformCollection内各个元素的资源
	std::map<std::string, Uniform*>::iterator it = _uniforms.begin();
	while (it != _uniforms.end()) {
		delete it->second;
		it->second = nullptr;
		it++;
	}

	for (auto it = _linkAutoUniforms.begin(); it != _linkAutoUniforms.end(); it++) {
		delete it->second;
		it->second = nullptr;
	}

	for (auto it = _drawAutoUniformFactories.begin(); it != _drawAutoUniformFactories.end(); it++) {
		delete it->second;
		it->second = nullptr;
	}

	for (auto it = _drawAutoUniforms.begin(); it != _drawAutoUniforms.end(); it++) {
		delete (*it);
	}
}

void ShaderProgram::use() {
	glUseProgram(_program);
}

void ShaderProgram::clean(Context* context, DrawState* drawState, SceneState* sceneState) {
	// 通过DrawAutoUniformCollection中保存的各个DrawAutoUniform为各个对应的Uniform自动设置值
	setDrawAutoUniforms(context, drawState, sceneState);

	// 使用GL调用将Uniform值传送到GPU
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
		vertexAttributes.push_back(new ShaderVertexAttribute(attributeName, attributeLocation,
			attributeType, attributeSize));
	}
	return vertexAttributes;
};

UniformCollection ShaderProgram::findUniforms(GLuint program) {
	// 获取激活的Uniform变量的个数
	int numberOfUniforms;
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numberOfUniforms);

	// 获取激活的Uniform变量的变量名的最大长度
	int uniformNameMaxLength;
	glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniformNameMaxLength);

	UniformCollection uniforms;
	for (int i = 0; i < numberOfUniforms; i++) {
		int uniformNameLength;		// uniform变量名的长度
		int uniformSize;			// 
		GLenum uniformType;			// uniform变量的类型
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
		return new UniformInt(name, location, type, this);
	case GL_FLOAT:
		return new UniformFloat(name, location, type, this);
	}
	throw std::invalid_argument("An implementation for argument uniform type does not exist.");
};



void ShaderProgram::initAutoUniforms(UniformCollection uniforms) {
	for (std::map<std::string, Uniform*>::iterator it = uniforms.begin(); it != uniforms.end(); it++) {
		std::string name = it->first;
		Uniform* uniform = it->second;
		if (_linkAutoUniforms.find(name) != _linkAutoUniforms.end()) {
			// 为与LinkAutoUniform对应的Uniform设置自动计算的值
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
	for (auto it = _drawAutoUniforms.begin(); it != _drawAutoUniforms.end(); it++) {
		(*it)->set(context, drawState, sceneState);
	}
};