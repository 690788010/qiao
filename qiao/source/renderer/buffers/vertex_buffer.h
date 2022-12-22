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
	 * VertexBuffer�������ڱ��涥�����ݵĻ���.
	 */
	class VertexBuffer {
	public:
		VertexBuffer(GLenum usage, GLsizeiptr sizeInBytes);
		~VertexBuffer();

		void bind();
		void unBind();

		// �����ݴ�ϵͳ�ڴ渴�Ƶ�GPU�Դ�
		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
		// �����ݴ�GPU�Դ渴�Ƶ�ϵͳ�ڴ�
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLenum getUsage();
		GLsizeiptr getSizeInBytes();

	private:
		Buffer* _buffer;
	};
}