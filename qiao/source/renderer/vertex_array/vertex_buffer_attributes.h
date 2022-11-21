#pragma once

#include "vertex_buffer_attribute.h"

namespace qiao {
	class VertexBufferAttributes {
	public:
		virtual VertexBufferAttribute* getByIndex(unsigned int index) = 0;
		virtual void setByIndex(unsigned int index, VertexBufferAttribute* value) = 0;
		virtual void clean() = 0;
		virtual unsigned int getCount();
	};
}