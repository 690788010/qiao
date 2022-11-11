#pragma once
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class BufferGL3x {
	public:
		BufferGL3x(GLenum target, GLenum usage, GLsizeiptr sizeInBytes);
		~BufferGL3x();

		void bind();
		GLuint getBuffer();
		GLenum getTarget();
		GLsizeiptr getSizeInBytes();

	private:
		GLuint _buffer;
		GLenum _target;
		GLenum _usage;
		GLsizeiptr _sizeInBytes;
	};
}