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
	 * Buffer类表示OpenGL的显存缓冲.它为IndexBuffer类和VertexBuffer类提供底层操作
	 */
	class Buffer {
	public:
		/**
		 * 构造函数.
		 * 
		 * \param target 缓存绑定目标
		 * \param usage	用例参数		
		 * \param sizeInBytes 缓存的字节大小
		 */
		Buffer(GLenum target, GLenum usage, GLsizeiptr sizeInBytes);
		~Buffer();

		// 为缓存绑定目标
		void bind();

		// 解绑
		void unBind();

		// 从内存数据拷贝
		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
		// 将数据拷贝到内存
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