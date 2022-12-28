#pragma once

#include "buffer.h"

namespace qiao {
	class WritePixelBuffer {
	public:
		WritePixelBuffer(GLenum usage, GLsizeiptr sizeInBytes);
		~WritePixelBuffer();

		void bind();
		void unBind();

		// 将数据从系统内存复制到GPU显存
		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
		// 将数据从GPU显存复制到系统内存
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLenum getUsage();
		GLsizeiptr getSizeInBytes();

	private:
		Buffer* _buffer;
	};
}
