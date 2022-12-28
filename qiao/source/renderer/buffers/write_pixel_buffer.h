#pragma once

#include "buffer.h"

namespace qiao {
	class WritePixelBuffer {
	public:
		WritePixelBuffer(GLenum usage, GLsizeiptr sizeInBytes);
		~WritePixelBuffer();

		void bind();
		void unBind();

		// �����ݴ�ϵͳ�ڴ渴�Ƶ�GPU�Դ�
		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
		// �����ݴ�GPU�Դ渴�Ƶ�ϵͳ�ڴ�
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLenum getUsage();
		GLsizeiptr getSizeInBytes();

	private:
		Buffer* _buffer;
	};
}
