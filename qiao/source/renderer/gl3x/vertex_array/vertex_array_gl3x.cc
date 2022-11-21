#include "vertex_array_gl3x.h"

using namespace qiao;

VertexArrayGL3x::VertexArrayGL3x() {
	glGenVertexArrays(1, &_vao);
	_attributes = new VertexBufferAttributesGL3x();
	_indexBuffer = nullptr;
	_dirtyIndex = false;
};

VertexArrayGL3x::~VertexArrayGL3x() {
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

void VertexArrayGL3x::clean() {
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

void VertexArrayGL3x::bind() {
	glBindVertexArray(_vao);
};

VertexBufferAttributesGL3x* VertexArrayGL3x::getAttributes() {
	return _attributes;
};

IndexBufferGL3x* VertexArrayGL3x::getIndexBuffer() {
	return _indexBuffer;
};

void VertexArrayGL3x::setIndexBuffer(IndexBuffer* indexBuffer) {
	_indexBuffer = (IndexBufferGL3x*)indexBuffer;
	_dirtyIndex = true;
};