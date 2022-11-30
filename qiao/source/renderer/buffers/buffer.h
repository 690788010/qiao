#pragma once

#include <iostream>
#include <stdexcept>
#include "../../../third_party/glad/include/glad.h"

namespace qiao {
	class Buffer {
	public:
		Buffer(GLenum target, GLenum usage, GLsizeiptr sizeInBytes);
		~Buffer();

		void bind();
		void unBind();

		void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size);
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