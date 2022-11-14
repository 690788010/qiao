#pragma once
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class BufferGL3x {
	public:
		BufferGL3x(GLenum target, GLenum usage, GLsizeiptr sizeInBytes);
		~BufferGL3x();

		void bind();
		void unBind();

		template<typename T>
		void copyFromSystemMemory(T data[], unsigned int offset, unsigned int size);
		void* copyToSystemMemory(unsigned int perElementSize, unsigned int offset, unsigned int size);

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