#include "buffer_gl3x.h"

using namespace qiao;

BufferGL3x::BufferGL3x(GLenum target, GLenum usage, GLsizeiptr sizeInBytes) :
	_target{ target }, _usage{ usage }, _sizeInBytes{sizeInBytes}
{
	glGenBuffers(1, &_buffer);
	
	glBindVertexArray(0);
	bind();
	glBufferData(_target, _sizeInBytes, nullptr, _usage);
};

BufferGL3x::~BufferGL3x() {
	if (_buffer != 0) {
		glDeleteBuffers(1, &_buffer);
		_buffer = 0;
	}
};

void BufferGL3x::bind() {
	glBindBuffer(_target, _buffer);
};

GLuint BufferGL3x::getBuffer() {
	return _buffer;
};

GLenum BufferGL3x::getTarget() {
	return _target;
};

GLsizeiptr BufferGL3x::getSizeInBytes() {
	return _sizeInBytes;
};