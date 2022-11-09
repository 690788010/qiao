
#include <iostream>
#include "shader_program.h"
#include "draw_auto_uniforms/model_matrix_uniform_factory.h"

using namespace qiao;

ShaderProgram::ShaderProgram() {
	int _numberOfTextureUnits;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &_numberOfTextureUnits);
	for (int i = 0; i < _numberOfTextureUnits; i++) {
		_linkAutoUniforms.insert(std::pair<std::string, LinkAutoUniform*>("og_texture" + i, new TextureUniform(i)));
	}

	_drawAutoUniformFactories.insert(
		std::pair<std::string, DrawAutoUniformFactory*>("og_modelMatrix", new ModelMatrixUniformFactory()));

}

ShaderProgram::~ShaderProgram() {
	std::cout << "~ShaderProgram" << std::endl;

	for (auto it = _linkAutoUniforms.begin(); it != _linkAutoUniforms.end(); it++) {
		delete it->second;
	}

	for (auto it = _drawAutoUniformFactories.begin(); it != _drawAutoUniformFactories.end(); it++) {
		delete it->second;
	}

	for (auto it = _drawAutoUniforms.begin(); it != _drawAutoUniforms.end(); it++) {
		delete (*it);
	}
}

void ShaderProgram::initAutoUniforms(UniformCollection uniforms) {
	for (std::map<std::string, Uniform*>::iterator it = uniforms.begin(); it != uniforms.end(); it++) {
		std::string name = it->first;
		Uniform* uniform = it->second;
		if (_linkAutoUniforms.find(name) != _linkAutoUniforms.end()) {
			// 为与LinkAutoUniform对应的Uniform设置自动计算的值
			_linkAutoUniforms[name]->set(uniform);
		}
		else if (_drawAutoUniformFactories.find(name) != _drawAutoUniformFactories.end()) {
			DrawAutoUniform* drawAutoUniform = _drawAutoUniformFactories[name]->create(uniform);
			_drawAutoUniforms.push_back(drawAutoUniform);
		}
	}
};