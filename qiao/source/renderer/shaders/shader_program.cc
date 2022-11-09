
#include <iostream>
#include "shader_program.h"

using namespace qiao;

ShaderProgram::ShaderProgram() {
	int _numberOfTextureUnits;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &_numberOfTextureUnits);
	for (int i = 0; i < _numberOfTextureUnits; i++) {
		_linkAutoUniforms.insert(std::pair<std::string, LinkAutoUniform*>("og_texture" + i, new TextureUniform(i)));
	}
}

ShaderProgram::~ShaderProgram() {
	std::cout << "~ShaderProgram" << std::endl;
}

void ShaderProgram::initAutoUniforms(UniformCollection uniforms) {
	for (std::map<std::string, Uniform*>::iterator it = uniforms.begin(); it != uniforms.end(); it++) {
		if (_linkAutoUniforms.find(it->first) != _linkAutoUniforms.end()) {
			// 为与LinkAutoUniform对应的Uniform设置自动计算的值
			_linkAutoUniforms[it->first]->set(it->second);
		}
	}
};