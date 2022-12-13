#include "vertex_buffer_attribute.h"

using namespace qiao;

VertexBufferAttribute::VertexBufferAttribute(VertexBuffer* vertexBuffer, GLint size, GLenum type,
	GLboolean normalized, GLsizei stride, unsigned int offset) {
	_vertexBuffer = vertexBuffer;
	_size = size;
	_type = type;
	_normalized = normalized;
	_stride = stride;
	_offset = offset;
};

VertexBufferAttribute::~VertexBufferAttribute() {
	/*if (_vertexBuffer != nullptr) {
		delete _vertexBuffer;
		_vertexBuffer = nullptr;
	}*/
};

VertexBuffer* VertexBufferAttribute::getVertexBuffer() {
	return _vertexBuffer;
};

GLint VertexBufferAttribute::getSize() {
	return _size;
};

GLenum VertexBufferAttribute::getType() {
	return _type;
};

GLboolean VertexBufferAttribute::getNormalized() {
	return _normalized;
};

GLsizei VertexBufferAttribute::getStride() {
	return _stride;
};

unsigned int VertexBufferAttribute::getOffset() {
	return _offset;
};
