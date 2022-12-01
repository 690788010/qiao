#pragma once

#include "vertex_buffer_attributes.h"
#include "../buffers/index_buffer.h"

namespace qiao {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		void bind();
		// 同步各个VertexBufferAttribute（包含在VertexBufferAttributes中）和IndexBuffer
		void clean();

		virtual VertexBufferAttributes* getAttributes();
		virtual IndexBuffer* getIndexBuffer();
		virtual void setIndexBuffer(IndexBuffer* indexBuffer);

	private:
		unsigned int _vao;
		VertexBufferAttributes* _attributes;
		IndexBuffer* _indexBuffer;
		bool _dirtyIndex;
	};
}