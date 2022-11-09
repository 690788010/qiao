#include "texture_uniform.h"

using namespace qiao;

TextureUniform::TextureUniform(int textureUnit) {
	_textureUnit = textureUnit;
};

// ��ȡUniform������
std::string TextureUniform::getName() {
	return "og_texture" + _textureUnit;
};

// ΪUniform����ֵ
void TextureUniform::set(Uniform* uniform) {
	((UniformGeneric<int>*)uniform)->setValue(_textureUnit);
};