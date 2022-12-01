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
		bool* _dirties;						// ��ʶ��Ӧ��VertexBufferAttribute�Ƿ�δͬ����OpenGL
		unsigned int _count;				// ��ɫ���е�ǰ���ڼ���״̬��Vertex Attribute������
		bool _dirty;                        // �Ƿ���VertexBufferAttributeδͬ����OpenGL
		int _maxVertexAttribs;				// the maximum number of 4-component generic vertex attributes accessible to a vertex shader
	};
}