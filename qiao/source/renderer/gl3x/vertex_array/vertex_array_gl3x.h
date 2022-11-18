#pragma once

#include "../../vertex_array/vertex_array.h"
#include "vertex_buffer_attributes_gl3x.h"
#include "../buffers/index_buffer_gl3x.h"

namespace qiao {
	class VertexArrayGL3x : public VertexArray {
	public:
		VertexArrayGL3x();
		~VertexArrayGL3x();

		VertexBufferAttributesGL3x* getAttributes();
		IndexBufferGL3x* getIndexBuffer();
		void setIndexBuffer(IndexBufferGL3x* indexBuffer);

	private:
		VertexBufferAttributesGL3x* _atttributes;
		IndexBufferGL3x* _indexBuffer;
	};
}