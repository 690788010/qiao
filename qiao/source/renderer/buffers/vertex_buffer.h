/*****************************************************************//**
 * \file   vertex_buffer.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "buffer.h"

namespace qiao {
	/**
	 * VertexBuffer类是用于保存顶点数据的缓存.
	 */
	class VertexBuffer {
	public:
		VertexBuffer(GLenum usage, GLsizeiptr sizeInBytes);
		~VertexBuffer();

		void bind();
		void unBind();

		// 将数据从系统内存复制到GPU显存
		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
		// 将数据从GPU显存复制到系统内存
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLenum getUsage();
		GLsizeiptr getSizeInBytes();

	private:
		Buffer* _buffer;
	};
}