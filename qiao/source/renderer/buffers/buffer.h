/*****************************************************************//**
 * \file   buffer.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <iostream>
#include <stdexcept>
#include "../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * Buffer���ʾOpenGL���Դ滺��.��ΪIndexBuffer���VertexBuffer���ṩ�ײ����
	 */
	class Buffer {
	public:
		/**
		 * ���캯��.
		 * 
		 * \param target �����Ŀ��
		 * \param usage	��������		
		 * \param sizeInBytes ������ֽڴ�С
		 */
		Buffer(GLenum target, GLenum usage, GLsizeiptr sizeInBytes);
		~Buffer();

		// Ϊ�����Ŀ��
		void bind();

		// ���
		void unBind();

		// ���ڴ����ݿ���
		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
		// �����ݿ������ڴ�
		void copyToSystemMemory(void* data, unsigned int offset, unsigned int size);

		GLuint getBuffer();
		GLenum getTarget();
		GLenum getUsage();
		GLsizeiptr getSizeInBytes();

	private:
		GLuint _buffer;
		GLenum _target;
		GLenum _usage;
		GLsizeiptr _sizeInBytes;		// unsigned int
	};
}