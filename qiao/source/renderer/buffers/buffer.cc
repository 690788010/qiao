#include <iostream>
#include <stdexcept>
#include "buffer.h"

using namespace qiao;

Buffer::Buffer(GLenum target, GLenum usage, GLsizeiptr sizeInBytes) :
	_target{ target }, _usage{ usage }, _sizeInBytes{sizeInBytes}
{
	glGenBuffers(1, &_buffer);
	
	glBindVertexArray(0);
	bind();
	glBufferData(_target, _sizeInBytes, nullptr, _usage);
};

Buffer::~Buffer() {
	if (_buffer != 0) {
		glDeleteBuffers(1, &_buffer);
		_buffer = 0;
	}
};

void Buffer::bind() {
	glBindBuffer(_target, _buffer);
};

void Buffer::unBind() {
	glBindBuffer(_target, 0);
};

void Buffer::copyFromSystemMemory(void* data, unsigned int offset, unsigned int size) {
	if (size == 0) {
		throw std::invalid_argument("size must be greater than zero!");
	}
	if (offset + size > _sizeInBytes) {
		throw std::invalid_argument("offset + size must be less than or equal to _sizeInBytes!");
	}
	glBindVertexArray(0);
	bind();
	glBufferSubData(_target, offset, size, data);
};

void Buffer::copyToSystemMemory(void* data, unsigned int offset, unsigned int size) {
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

GLuint Buffer::getBuffer() {
	return _buffer;
};

GLenum Buffer::getTarget() {
	return _target;
};

GLenum Buffer::getUsage() {
	return _usage;
};

GLsizeiptr Buffer::getSizeInBytes() {
	return _sizeInBytes;
};