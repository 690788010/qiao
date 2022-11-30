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
	_enabled = true;
};

VertexBufferAttribute::~VertexBufferAttribute() {
	if (_vertexBuffer != nullptr) {
		delete _vertexBuffer;
		_vertexBuffer = nullptr;
	}
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

bool VertexBufferAttribute::getEnabled() {
	return _enabled;
};

void VertexBufferAttribute::setEnabled(bool val) {
	_enabled = val;
};

bool VertexBufferAttribute::getDirty() {
	return _dirty;
};

void VertexBufferAttribute::setDirty(bool val) {
	_dirty = val;
};

bool VertexBufferAttribute::operator==(VertexBufferAttribute* attribute) {
	if (_vertexBuffer != attribute->getVertexBuffer()) {
		return false;
	}
	if (_size != attribute->getSize()) {
		return false;
	}
	if (_type != attribute->getType()) {
		return false;
	}
	if (_normalized != attribute->getNormalized()) {
		return false;
	}
	if (_stride != attribute->getStride()) {
		return false;
	}
	if (_offset != attribute->getOffset()) {
		return false;
	}
	if (_dirty != attribute->getDirty()) {
		return false;
	}
	return true;
};
