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
		bool* _dirties;						// 标识对应的VertexBufferAttribute是否未同步到OpenGL
		unsigned int _count;				// 着色器中当前处于激活状态的Vertex Attribute的数量
		bool _dirty;                        // 是否又VertexBufferAttribute未同步到OpenGL
		int _maxVertexAttribs;				// the maximum number of 4-component generic vertex attributes accessible to a vertex shader
	};
}