#include "index_buffer.h"

using namespace qiao;

IndexBuffer::IndexBuffer(GLenum usage, GLsizeiptr sizeInBytes) {
	_type = 0;
	_count = 0;
	_buffer = new Buffer(GL_ELEMENT_ARRAY_BUFFER, usage, sizeInBytes);
};

IndexBuffer::~IndexBuffer() {
	if (_buffer != nullptr) {
		delete _buffer;
		_buffer = nullptr;
	}
};

void IndexBuffer::bind() {
	_buffer->bind();
};

void IndexBuffer::unBind() {
	_buffer->unBind();
};

void IndexBuffer::copyFromSystemMemory(void* data, GLenum type, unsigned int offset, unsigned int size) {
	_type = type;
	int typeSize = 0;
	switch (_type) {
		case GL_UNSIGNED_BYTE: typeSize = 1; break;
		case GL_UNSIGNED_SHORT: typeSize = 2; break;
		case GL_UNSIGNED_INT: typeSize = 4; break;
		default: throw std::invalid_argument("argument dataType is incorrect!"); break;
	}
	_count = _buffer->getSizeInBytes() / typeSize;
	_buffer->copyFromSystemMemory(data, offset, size);
};

void IndexBuffer::copyToSystemMemory(void* data, unsigned int offset, unsigned int size) {
	_buffer->copyToSystemMemory(data, offset, size);
};

GLenum IndexBuffer::getUsage() {
	return _buffer->getUsage();
};

GLsizeiptr IndexBuffer::getSizeInBytes() {
	return _buffer->getSizeInBytes();
};

GLenum IndexBuffer::getType() {
	return  _type;
};