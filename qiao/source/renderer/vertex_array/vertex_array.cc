#include "vertex_array.h"

using namespace qiao;

VertexArray::VertexArray() {
	glGenVertexArrays(1, &_vao);
	_attributes = new VertexBufferAttributes();
	_indexBuffer = nullptr;
	_dirtyIndex = false;
};

VertexArray::~VertexArray() {
	if (_vao != 0) {
		glDeleteVertexArrays(1, &_vao);
		_vao = 0;
	}
	if (_attributes != nullptr) {
		delete _attributes;
		_attributes = nullptr;
	}
	if (_indexBuffer != nullptr) {
		delete _indexBuffer;
		_indexBuffer = nullptr;
	}
};

void VertexArray::bind() {
	glBindVertexArray(_vao);
};

void VertexArray::clean() {
	_attributes->clean();
	if (_dirtyIndex) {
		if (_indexBuffer != nullptr) {
			_indexBuffer->bind();
		}
		else {
			_indexBuffer->unBind();
		}
		_dirtyIndex = false;
	}
};

VertexBufferAttributes* VertexArray::getAttributes() {
	return _attributes;
};

IndexBuffer* VertexArray::getIndexBuffer() {
	return _indexBuffer;
};

void VertexArray::setIndexBuffer(IndexBuffer* indexBuffer) {
	_indexBuffer = indexBuffer;
	_dirtyIndex = true;
};