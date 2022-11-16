#pragma once

#include "../../vertex_array/vertex_buffer_attributes.h"
#include "vertex_buffer_attribute_gl3x.h"

namespace qiao {
	class VertexBufferAttributesGL3x : public qiao::VertexBufferAttributes {
	public:
		VertexBufferAttributesGL3x();
		~VertexBufferAttributesGL3x();

	private:
		VertexBufferAttributeGL3x** _attributes;
	};
}