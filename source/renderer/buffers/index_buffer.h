/*****************************************************************//**
 * \file   index_buffer.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "buffer.h"

namespace qiao {
	/**
	 * IndexBuffer���Ǳ��涥��������Ϣ�Ļ���.
	 */
	class IndexBuffer {
	public:
		IndexBuffer(GLenum usage, GLsizeiptr sizeInBytes);
		~IndexBuffer();

		void bind();
		void unBind();

		// �����ݴ�ϵͳ�ڴ渴�Ƶ�GPU�Դ棬type��������Ϊ GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, �� GL_UNSIGNED_INT
		void copyFromSystemMemory(void* data, GLenum type, unsigned int offset, unsigned int size);
		// �����ݴ�GPU�Դ渴�Ƶ�ϵͳ�ڴ�
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLenum getUsage();
		GLsizeiptr getSizeInBytes();
		GLenum getType();
		unsigned int getCount();

	private:
		Buffer* _buffer;
		GLenum _type;			    // data type. Must be one of GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT.
		unsigned int _count;		// the number of elements to be rendered.
	};
}