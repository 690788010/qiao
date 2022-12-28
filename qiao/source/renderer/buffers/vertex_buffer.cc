#include "vertex_buffer.h"

using namespace qiao;

VertexBuffer::VertexBuffer(GLenum usage, GLsizeiptr sizeInBytes) {
	// 解绑VAO，使缓存不与任何VAO关联
	glBindVertexArray(0);
	_buffer = new Buffer(GL_ARRAY_BUFFER, usage, sizeInBytes);
}

VertexBuffer::~VertexBuffer() {
	if (_buffer != nullptr) {
		delete _buffer;
		_buffer = nullptr;
	}
};

void VertexBuffer::bind() {
	_buffer->bind();
};

void VertexBuffer::unBind() {
	_buffer->unBind();
};

void VertexBuffer::copyFromSystemMemory(void* data, unsigned int offset, unsigned int size) {
	glBindVertexArray(0);
	_buffer->copyFromSystemMemory(data, offset, size);
};

void VertexBuffer::copyToSystemMemory(void* data, unsigned int offset, unsigned int size) {
	glBindVertexArray(0);
	_buffer->copyToSystemMemory(data, offset, size);
};

GLenum VertexBuffer::getUsage() {
	return _buffer->getUsage();
};

GLsizeiptr VertexBuffer::getSizeInBytes() {
	return _buffer->getSizeInBytes();
};