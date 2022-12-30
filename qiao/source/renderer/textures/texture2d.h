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
		 * ��������ض��ж��뷽ʽͼƬ��ռ���ֽ���.
		 * 
		 * \param width ͼƬ�Ŀ�� 
		 * \param height ͼƬ�ĸ߶�
		 * \param format ͼƬ���ص����ݸ�ʽ
		 * \param type ͼƬ���ص���������
		 * \param rowAlignment �ж�����ֽ���
		 */
		int _requiredSizeInBytes(int width, int height, GLenum format, GLenum type, int rowAlignment);

		/**
		 * ����ͼƬ���ص����ݸ�ʽformat����ɫͨ����.
		 * 
		 * \param format
		 * \return 
		 */
		int _numberOfChannels(GLenum format);

		/**
		 * ����ͼƬ���ص���������type��Ӧ���ֽ���.
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
