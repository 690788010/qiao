/*****************************************************************//**
 * \file   vertex_array.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "vertex_buffer_attributes.h"
#include "../buffers/index_buffer.h"

namespace qiao {
	/**
	 * VertexArray类表示VAO并提供相关功能操作.
	 */
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		// 绑定VAO
		void bind();

		// 同步各个VertexBufferAttribute（包含在VertexBufferAttributes中）和IndexBuffer
		void clean();

		virtual VertexBufferAttributes& getAttributes();

		virtual IndexBuffer* getIndexBuffer();
		virtual void setIndexBuffer(IndexBuffer* indexBuffer);

	private:
		unsigned int _vao;
		VertexBufferAttributes _attributes;
		IndexBuffer* _indexBuffer;
		bool _dirtyIndex;			// 标识indexBuffer是否设置了新值
	};
}