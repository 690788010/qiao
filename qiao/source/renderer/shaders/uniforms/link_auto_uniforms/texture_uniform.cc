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

// ��ȡUniform������
std::string TextureUniform::getName() {
	return "og_texture" + _textureUnit;		// ��ɫ����Sampler Uniform��������֮һ�²���ƥ��
};

// ΪUniform����ֵ
void TextureUniform::set(Uniform* uniform) {
	// ������ת��UniformGeneric<int>��ָ�룬���ܵ���setValue��������ֵ
	((UniformGeneric<int>*)uniform)->setValue(_textureUnit);
};