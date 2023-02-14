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
	 * VertexArray���ʾVAO���ṩ��ع��ܲ���.
	 */
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		// ��VAO
		void bind();

		// ͬ������VertexBufferAttribute��������VertexBufferAttributes�У���IndexBuffer
		void clean();

		virtual VertexBufferAttributes& getAttributes();

		virtual IndexBuffer* getIndexBuffer();
		virtual void setIndexBuffer(IndexBuffer* indexBuffer);

	private:
		unsigned int _vao;
		VertexBufferAttributes _attributes;
		IndexBuffer* _indexBuffer;
		bool _dirtyIndex;			// ��ʶindexBuffer�Ƿ���������ֵ
	};
}