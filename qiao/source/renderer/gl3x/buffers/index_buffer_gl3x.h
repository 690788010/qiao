#pragma once

#include "../../buffers/index_buffer.h"
#include "buffer_gl3x.h"

namespace qiao {
	class IndexBufferGL3x : public IndexBuffer {
	public:
		IndexBufferGL3x(GLenum usage, GLsizeiptr sizeInBytes);
		~IndexBufferGL3x();

		void bind();
		void unBind();

		virtual void copyFromSystemMemory(void* data, IndexBufferDataType dataType, unsigned int offset, unsigned int size);
		virtual void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		virtual unsigned int getUsage();
		virtual unsigned int getSizeInBytes();
		virtual unsigned int getDataType();

	private:
		BufferGL3x* _bufferGL3x;
		unsigned int _dataType;
		unsigned int _count;		// the number of elements to be rendered.
	};
}