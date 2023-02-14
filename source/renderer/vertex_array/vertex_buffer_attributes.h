/*****************************************************************//**
 * \file   vertex_buffer_attributes.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "vertex_buffer_attribute.h"

namespace qiao {
	/**
	 * VertexBufferAttributes����VertexBufferAttribute����ָ���������ͬʱ���ṩ����ص�GLͬ������
	 */
	class VertexBufferAttributes {
	public:
		VertexBufferAttributes();
		~VertexBufferAttributes();

		VertexBufferAttribute* getByIndex(unsigned int index);
		void setByIndex(unsigned int index, VertexBufferAttribute* value);

		// ��������ͬ����GL
		void clean();

		// ����ض������������ͬ����GL������ö�������
		void attach(unsigned index);
		// ȡ�������ض��Ķ�������
		void detach(unsigned index);

		unsigned int getCount();

	private:
		VertexBufferAttribute** _attributes;
		bool* _dirties;						// ��ʶ��Ӧ��VertexBufferAttribute�Ƿ�δͬ����OpenGL
		bool _dirty;                        // �Ƿ���VertexBufferAttributeδͬ����OpenGL
		unsigned int _count;				// ��ɫ���е�ǰ���ڼ���״̬��Vertex Attribute������
		int _maxVertexAttribs;				// the maximum number of 4-component generic vertex attributes accessible to a vertex shader
	};
}