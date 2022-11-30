#pragma once

#include "buffer.h"

namespace qiao {
	class IndexBuffer {
	public:
		IndexBuffer(GLenum usage, GLsizeiptr sizeInBytes);
		~IndexBuffer();

		void bind();
		void unBind();

		// 将数据从系统内存复制到GPU显存，type参数必须为 GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, 或 GL_UNSIGNED_INT
		void copyFromSystemMemory(void* data, GLenum type, unsigned int offset, unsigned int size);
		// 将数据从GPU显存复制到系统内存
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLenum getUsage();
		GLsizeiptr getSizeInBytes();
		GLenum getType();

	private:
		Buffer* _buffer;
		GLenum _type;			    // data type. Must be one of GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT.
		unsigned int _count;		// the number of elements to be rendered.
	};
}