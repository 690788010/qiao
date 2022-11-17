#pragma once

#include "../../vertex_array/vertex_buffer_attributes.h"
#include "vertex_buffer_attribute_gl3x.h"

namespace qiao {
	class VertexBufferAttributesGL3x : public qiao::VertexBufferAttributes {
	public:
		VertexBufferAttributesGL3x();
		~VertexBufferAttributesGL3x();

		virtual VertexBufferAttributeGL3x* getByIndex(unsigned index);
		virtual void setByIndex(unsigned index, VertexBufferAttributeGL3x* value);
		virtual void clean();
		void attach(unsigned index);
		void detach(unsigned index);

	private:
		VertexBufferAttributeGL3x** _attributes;
		unsigned int _count;
		bool _dirty;
	};
}