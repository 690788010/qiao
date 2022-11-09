#include "texture_uniform.h"

using namespace qiao;

TextureUniform::TextureUniform(int textureUnit) {
	_textureUnit = textureUnit;
};

// 获取Uniform变量名
std::string TextureUniform::getName() {
	return "og_texture" + _textureUnit;
};

// 为Uniform设置值
void TextureUniform::set(Uniform* uniform) {
	((UniformGeneric<int>*)uniform)->setValue(_textureUnit);
};