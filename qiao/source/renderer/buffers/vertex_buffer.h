#pragma once

#include "buffer.h"

namespace qiao {
	class VertexBuffer {
	public:
		VertexBuffer(GLenum usage, GLsizeiptr sizeInBytes);
		~VertexBuffer();

		void bind();
		void unBind();

		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLenum getUsage();
		GLsizeiptr getSizeInBytes();

	private:
		Buffer* _buffer;
	};
}