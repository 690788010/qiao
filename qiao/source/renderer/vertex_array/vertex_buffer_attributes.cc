
#include <stdexcept>

#include "vertex_buffer_attributes.h"
#include "../../../third_party/glad/include/glad.h"

using namespace qiao;

VertexBufferAttributes::VertexBufferAttributes() {
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &_maxVertexAttribs);
	_attributes = new VertexBufferAttribute*[_maxVertexAttribs];
	_dirties = new bool[_maxVertexAttribs];
	for (int i = 0; i < _maxVertexAttribs; i++) {
		_dirties[i] = false;
	}
}

VertexBufferAttributes::~VertexBufferAttributes() {
	if (_attributes != nullptr) {
		for (int i = 0; i < _count; i++) {
			delete _attributes[i];
			_attributes[i] = nullptr;
		}
		delete[] _attributes;
		_attributes = nullptr;
	}
	if (_dirties != nullptr) {
		delete[] _dirties;
	}
};

VertexBufferAttribute* VertexBufferAttributes::getByIndex(unsigned index) {
	return _attributes[index];
};

void VertexBufferAttributes::setByIndex(unsigned int index, VertexBufferAttribute* value)
{
	if (_attributes[index] != value) {			
		if (value != nullptr) {
			if (value->getSize() < 1 || value->getSize() > 4) {
				throw std::invalid_argument("NumberOfComponents must be between one and four!");
			}
			if (value->getNormalized()) {
				unsigned int dataType = value->getType();
				if ((dataType != GL_BYTE) &&
					(dataType != GL_UNSIGNED_BYTE) &&
					(dataType != GL_SHORT) &&
					(dataType != GL_UNSIGNED_SHORT) &&
					(dataType != GL_INT) &&
					(dataType != GL_UNSIGNED_INT))
				{
					throw std::invalid_argument("When Normalize is true, type must be GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT, GL_INT, or GL_UNSIGNED_INT.");
				}
			}
			if (_attributes[index] == nullptr) {
				_count++;
			}
		}
		else {
			if (_attributes[index] != nullptr) {
				_count--;
			}
		}
		_attributes[index] = value;
		_dirties[index] = true;
		_dirty = true;
	}
}

void VertexBufferAttributes::clean() {
	if (_dirty) {
		for (int i = 0; i < _maxVertexAttribs; i++) {
			if (_dirties[i]) {							// 对应的VertexBufferAttribute未同步到OpenGL
				if (_attributes[i] != nullptr) {
					attach(i);
				}
				else {
					detach(i);
				}
				_dirties[i] = false;
			}
		}
		_dirty = false;
	}
};

unsigned int VertexBufferAttributes::getCount() {
	return _count;
};

void VertexBufferAttributes::attach(unsigned index) {
	VertexBufferAttribute* attribute = _attributes[index];
	VertexBuffer* vertexBuffer = attribute->getVertexBuffer();
	vertexBuffer->bind();
	glVertexAttribPointer(index,
		attribute->getSize(),
		attribute->getType(),
		attribute->getNormalized(),
		attribute->getStride(),
		(void *)attribute->getOffset());
};

void VertexBufferAttributes::detach(unsigned index) {
	glDisableVertexAttribArray(index);
};