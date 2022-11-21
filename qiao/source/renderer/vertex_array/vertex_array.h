#pragma once

#include "vertex_buffer_attributes.h"
#include "../buffers/index_buffer.h"

namespace qiao {
	class VertexArray {
	public:
		virtual void clean() = 0;
		virtual VertexBufferAttributes* getAttributes() = 0;
		virtual IndexBuffer* getIndexBuffer() = 0;
		virtual void setIndexBuffer(IndexBuffer* indexBuffer) = 0;
	};
}