#include "vertex_buffer_gl3x.h"

using namespace qiao;

VertexBufferGL3x::VertexBufferGL3x(GLenum usage, GLsizeiptr sizeInBytes) {
	_bufferGL3x = new BufferGL3x(GL_ARRAY_BUFFER, usage, sizeInBytes);
}

VertexBufferGL3x::~VertexBufferGL3x() {
	if (_bufferGL3x != nullptr) {
		delete _bufferGL3x;
		_bufferGL3x = nullptr;
	}
};

void VertexBufferGL3x::bind() {
	_bufferGL3x->bind();
};

void VertexBufferGL3x::unBind() {
	_bufferGL3x->unBind();
};

void VertexBufferGL3x::copyFromSystemMemory(void* data, unsigned int offset, unsigned int size) {
	_bufferGL3x->copyFromSystemMemory(data, offset, size);
};

void VertexBufferGL3x::copyToSystemMemory(void* data, unsigned int offset, unsigned int size) {
	_bufferGL3x->copyToSystemMemory(data, offset, size);
};

unsigned int VertexBufferGL3x::getUsage() {
	return _bufferGL3x->getUsage();
};

unsigned int VertexBufferGL3x::getSizeInBytes() {
	return _bufferGL3x->getSizeInBytes();
};