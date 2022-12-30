#pragma once
#include "../../../third_party/glad/include/glad.h"
#include "../buffers/write_pixel_buffer.h"

namespace qiao {
	class Texture2D {
	public:
		Texture2D(GLenum target, GLint internalformat, int width, int height, 
			GLenum format, GLenum type, bool generateMipmaps);
		~Texture2D();

		void bind();

		void copyFromBuffer(WritePixelBuffer* writePixelBuffer, int xOffset, int yOffset, int width, int height, GLenum format,
			GLenum type, int rowAlignment);

	private:
		void _bindFirstTextureUnit();

		/**
		 * 计算基于特定行对齐方式图片所占的字节数.
		 * 
		 * \param width 图片的宽度 
		 * \param height 图片的高度
		 * \param format 图片像素的数据格式
		 * \param type 图片像素的数据类型
		 * \param rowAlignment 行对齐的字节数
		 */
		int _requiredSizeInBytes(int width, int height, GLenum format, GLenum type, int rowAlignment);

		/**
		 * 计算图片像素的数据格式format的颜色通道数.
		 * 
		 * \param format
		 * \return 
		 */
		int _numberOfChannels(GLenum format);

		/**
		 * 计算图片像素的数据类型type对应的字节数.
		 * 
		 * \param type
		 * \return 
		 */
		int _sizeInBytes(GLenum type);

		unsigned int _texture;
		GLenum _firstTextureUnit;
		GLenum _target;
		GLint _internalformat;
		int _width;
		int _height;
		GLenum _format;
		GLenum _type;
		bool _generateMipmaps;
	};
}
