#pragma once

#include "../../vertex_array/vertex_array.h"
#include "vertex_buffer_attributes_gl3x.h"
#include "../buffers/index_buffer_gl3x.h"

namespace qiao {
	class VertexArrayGL3x : public VertexArray {
	public:
		VertexArrayGL3x();
		~VertexArrayGL3x();

		virtual void clean();

		void bind();

		virtual VertexBufferAttributesGL3x* getAttributes();
		virtual IndexBufferGL3x* getIndexBuffer();
		virtual void setIndexBuffer(IndexBuffer* indexBuffer);

	private:
		unsigned int _vao;
		VertexBufferAttributesGL3x* _attributes;
		IndexBufferGL3x* _indexBuffer;
		bool _dirtyIndex;
	};
}