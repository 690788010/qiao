/*****************************************************************//**
 * \file   texture_uniform.cc
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/
#include "texture_uniform.h"

using namespace qiao;

TextureUniform::TextureUniform(int textureUnit) {
	_textureUnit = textureUnit;
};

// 获取Uniform变量名
std::string TextureUniform::getName() {
	return "og_texture" + _textureUnit;		// 着色器中Sampler Uniform变量名与之一致才能匹配
};

// 为Uniform设置值
void TextureUniform::set(Uniform* uniform) {
	// 先向上转成UniformGeneric<int>类指针，才能调用setValue方法设置值
	((UniformGeneric<int>*)uniform)->setValue(_textureUnit);
};