#include <stdexcept>
#include "texture2d.h"

using namespace qiao;

Texture2D::Texture2D(GLenum target, GLint internalformat, int width, int height,
	GLenum format, GLenum type, bool generateMipmaps) 
{
	if (width <= 0) {
		throw std::invalid_argument("width must be greater than zero!");
	}
	if (height <= 0) {
		throw std::invalid_argument("height must be greater than zero!");
	}
	_target = target;
	_internalformat = internalformat;
	_width = width;
	_height = height;
	_format = format;
	_type = type;
	_generateMipmaps = generateMipmaps;
	_firstTextureUnit = GL_TEXTURE0;

	glGenTextures(1, &_texture);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
	_bindFirstTextureUnit();
	glTexImage2D(_target, 0, _internalformat, _width, _height, 0, _format, _type, nullptr);
};

Texture2D::~Texture2D() {
	if (_texture != 0) {
		glDeleteTextures(1, &_texture);
		_texture = 0;
	}
};

void Texture2D::bind() {
	glBindTexture(_target, _texture);
};

void Texture2D::copyFromBuffer(WritePixelBuffer* writePixelBuffer, int xOffset, int yOffset, int width, int height, GLenum format,
	GLenum type, int rowAlignment) 
{
	
};

void Texture2D::_bindFirstTextureUnit() {
	glActiveTexture(_firstTextureUnit);
	bind();
};

int Texture2D::_requiredSizeInBytes(int width, int height, GLenum format, GLenum type, int rowAlignment) {
	// 图片实际的一行像素所占的空间
	int rowSize = width * _numberOfChannels(format) * _sizeInBytes(type);

	int remainder = rowSize % rowAlignment;
	// 符合字节对齐条件下图片一行像素所占的空间
	rowSize += ((rowAlignment - remainder) % rowAlignment);
	
	return rowSize * height;
};

int Texture2D::_numberOfChannels(GLenum format) {
	switch (format) {
	case GL_RED:
		return 1;
	case GL_RG:
		return 2;
	case GL_RGB:
	case GL_BGR:
		return 3;
	case GL_RGBA:
		return 4;
	}
	throw std::invalid_argument("invalid format!");
}

int Texture2D::_sizeInBytes(GLenum type) {
	switch (type) {
		case GL_UNSIGNED_BYTE:
		case GL_BYTE:
			return 1;
		case GL_UNSIGNED_SHORT:
		case GL_SHORT:
			return 2;
		case GL_UNSIGNED_INT:
		case GL_INT:
		case GL_FLOAT:
			return 4;
	}
};
