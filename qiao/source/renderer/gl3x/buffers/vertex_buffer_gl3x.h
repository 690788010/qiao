#pragma once

#include "../../buffers/vertex_buffer.h"
#include "buffer_gl3x.h"

namespace qiao {
	class VertexBufferGL3x : public VertexBuffer {
	public:
		VertexBufferGL3x(GLenum usage, GLsizeiptr sizeInBytes);
		~VertexBufferGL3x();

		void bind();
		void unBind();

		void copyFromSystemMemory(float data[], unsigned int offset, unsigned int size);

		void* copyToSystemMemory(unsigned int perElementSize, unsigned int offset, unsigned int size);

		virtual unsigned int getUsage();
		virtual unsigned int getSizeInBytes();

	private:
		BufferGL3x* _bufferGL3x;
	};
}