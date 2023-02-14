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
	 * VertexBufferAttributes类是VertexBufferAttribute对象指针的容器，同时它提供了相关的GL同步功能
	 */
	class VertexBufferAttributes {
	public:
		VertexBufferAttributes();
		~VertexBufferAttributes();

		VertexBufferAttribute* getByIndex(unsigned int index);
		void setByIndex(unsigned int index, VertexBufferAttribute* value);

		// 将新配置同步到GL
		void clean();

		// 将相关顶点的属性配置同步到GL并激活该顶点属性
		void attach(unsigned index);
		// 取消激活特定的顶点属性
		void detach(unsigned index);

		unsigned int getCount();

	private:
		VertexBufferAttribute** _attributes;
		bool* _dirties;						// 标识对应的VertexBufferAttribute是否未同步到OpenGL
		bool _dirty;                        // 是否又VertexBufferAttribute未同步到OpenGL
		unsigned int _count;				// 着色器中当前处于激活状态的Vertex Attribute的数量
		int _maxVertexAttribs;				// the maximum number of 4-component generic vertex attributes accessible to a vertex shader
	};
}