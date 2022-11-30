
#include <stdexcept>

#include "vertex_buffer_attributes.h"
#include "../../../third_party/glad/include/glad.h"

using namespace qiao;

VertexBufferAttributes::VertexBufferAttributes() {
	int numOfMaxVertexAttribs;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numOfMaxVertexAttribs);
	_attributes = new VertexBufferAttribute*[numOfMaxVertexAttribs];
}

VertexBufferAttributes::~VertexBufferAttributes() {
	if (_attributes != nullptr) {
		size_t len = sizeof(_attributes) / sizeof(_attributes[0]);
		for (size_t i = 0; i < len; i++) {
			delete _attributes[i];
			_attributes[i] = nullptr;
		}
		delete _attributes;
		_attributes = nullptr;
	}
};

VertexBufferAttribute* VertexBufferAttributes::getByIndex(unsigned index) {
	return _attributes[index];
};

void VertexBufferAttributes::setByIndex(unsigned int index, VertexBufferAttribute* value)
{
	if (!(_attributes[index] == value)) {				// ÖØÔØ¹ý==ÔËËã·û
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
		_attributes[index]->setDirty(true);
		_dirty = true;
	}
}

void VertexBufferAttributes::clean() {
	if (_dirty) {
		size_t len = sizeof(_attributes) / sizeof(_attributes[0]);
		for (size_t i = 0; i < len; i++) {
			if (_attributes[i] != nullptr) {
				if (_attributes[i]->getDirty()) {
					attach(i);
					_attributes[i]->setDirty(false);
				}
			}
			else {
				if (_attributes[i]->getDirty()) {
					detach(i);
					_attributes[i]->setDirty(false);
				}
			}
		}
		_dirty = false;
	}
};

unsigned int VertexBufferAttributesGL3x::getCount() {
	return _count;
};

void VertexBufferAttributesGL3x::attach(unsigned index) {
	VertexBufferAttributeGL3x* attribute = _attributes[index];
	VertexBufferGL3x* vertexBufferGL3x = (VertexBufferGL3x*)(attribute->getVertexBuffer());
	vertexBufferGL3x->bind();
	glVertexAttribPointer(index,
		attribute->getNumOfComponent(),
		attribute->getComponentDataType(),
		attribute->getNormalized(),
		attribute->getStrideInBytes(),
		(void *)attribute->getOffsetInBytes());
};

void VertexBufferAttributesGL3x::detach(unsigned index) {
	glDisableVertexAttribArray(index);
};