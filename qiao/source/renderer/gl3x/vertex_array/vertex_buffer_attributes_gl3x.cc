
#include <stdexcept>

#include "vertex_buffer_attributes_gl3x.h"
#include "../../../../third_party/glad/include/glad.h"
#include "../buffers/vertex_buffer_gl3x.h"


using namespace qiao;


VertexBufferAttributesGL3x::VertexBufferAttributesGL3x() {
	int numOfMaxVertexAttribs;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numOfMaxVertexAttribs);
	_attributes = new VertexBufferAttributeGL3x*[numOfMaxVertexAttribs];
}

VertexBufferAttributesGL3x::~VertexBufferAttributesGL3x() {
	if (_attributes != nullptr) {
		int len = sizeof(_attributes) / sizeof(_attributes[0]);
		for (int i = 0; i < len; i++) {
			delete _attributes[i];
		}
		delete _attributes;
		_attributes = nullptr;
	}
};

VertexBufferAttributeGL3x* VertexBufferAttributesGL3x::getByIndex(unsigned index) {
	return _attributes[index];
};

void VertexBufferAttributesGL3x::setByIndex(unsigned index, VertexBufferAttributeGL3x* value) {
	if (!(_attributes[index] == value)) {				// ÖØÔØ¹ý==ÔËËã·û
		if (value != nullptr) {
			if (value->getNumOfComponent() < 1 || value->getNumOfComponent() > 4) {
				throw std::invalid_argument("NumberOfComponents must be between one and four!");
			}
			if (value->getNormalized()) {
				unsigned int dataType = value->getComponentDataType();
				if ((dataType != GL_BYTE) &&
					(dataType != GL_UNSIGNED_BYTE) &&
					(dataType != GL_SHORT) &&
					(dataType != GL_UNSIGNED_SHORT) &&
					(dataType != GL_INT) &&
					(dataType != GL_UNSIGNED_INT))
				{
					throw std::invalid_argument("When Normalize is true, ComponentDatatype must be GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT, GL_INT, or GL_UNSIGNED_INT.");
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