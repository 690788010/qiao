#include <iostream>
#include <stdexcept>
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

void BufferGL3x::unBind() {
	glBindBuffer(_target, 0);
};

void BufferGL3x::copyFromSystemMemory(void* data, unsigned int offset, unsigned int size) {
	if (offset + size > _sizeInBytes) {
		throw std::invalid_argument("offset + size must be less than or equal to _sizeInBytes!");
	}
	glBindVertexArray(0);
	bind();
	glBufferSubData(_target, offset, size, data);
};

void BufferGL3x::copyToSystemMemory(void* data, unsigned int offset, unsigned int size) {
	if (size == 0) {
		throw std::invalid_argument("size must be greater than zero!");
	}
	if (offset + size > _sizeInBytes) {
		throw std::invalid_argument("offset + size must be less than or equal to _sizeInBytes.");
	}
	glBindVertexArray(0);
	bind();
	glGetBufferSubData(_target, offset, size, data);
};

GLuint BufferGL3x::getBuffer() {
	return _buffer;
};

GLenum BufferGL3x::getTarget() {
	return _target;
};

GLenum BufferGL3x::getUsage() {
	return _usage;
};

GLsizeiptr BufferGL3x::getSizeInBytes() {
	return _sizeInBytes;
};