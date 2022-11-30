#pragma once

#include "vertex_buffer_attribute.h"

namespace qiao {
	class VertexBufferAttributes {
	public:
		VertexBufferAttributes();
		~VertexBufferAttributes();

		VertexBufferAttribute* getByIndex(unsigned int index);
		void setByIndex(unsigned int index, VertexBufferAttribute* value);
		void clean();
		unsigned int getCount();
		void attach(unsigned index);
		void detach(unsigned index);

	private:
		VertexBufferAttribute** _attributes;
		unsigned int _count;
		bool _dirty;
	};
}