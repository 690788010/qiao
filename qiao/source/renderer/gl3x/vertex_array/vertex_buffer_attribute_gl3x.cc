#include "vertex_buffer_attribute_gl3x.h"

using namespace qiao;

VertexBufferAttributeGL3x::VertexBufferAttributeGL3x(VertexBuffer* vertexBuffer, unsigned int numOfComponent, unsigned int componentDataType,
	bool normalized, unsigned int strideInBytes, unsigned int offsetInBytes) {
	_vertexBuffer = vertexBuffer;
	_numOfComponent = numOfComponent;
	_componentDataType = componentDataType;
	_normalized = normalized;
	_strideInBytes = strideInBytes;
	_offsetInBytes = offsetInBytes;
};

VertexBufferAttributeGL3x::~VertexBufferAttributeGL3x() {
	if (_vertexBuffer != nullptr) {
		delete _vertexBuffer;
		_vertexBuffer = nullptr;
	}
};

VertexBuffer* VertexBufferAttributeGL3x::getVertexBuffer() {
	return _vertexBuffer;
};

unsigned int VertexBufferAttributeGL3x::getNumOfComponent() {
	return _numOfComponent;
};

unsigned int VertexBufferAttributeGL3x::getComponentDataType() {
	return _componentDataType;
};

bool VertexBufferAttributeGL3x::getNormalized() {
	return _normalized;
};

unsigned int VertexBufferAttributeGL3x::getStrideInBytes() {
	return _strideInBytes;
};

unsigned int VertexBufferAttributeGL3x::getOffsetInBytes() {
	return _offsetInBytes;
};

bool VertexBufferAttributeGL3x::getDirty() {
	return _dirty;
};

void VertexBufferAttributeGL3x::setDirty(bool val) {
	_dirty = val;
};

bool VertexBufferAttributeGL3x::operator==(VertexBufferAttribute* attribute) {
	if (_vertexBuffer != attribute->getVertexBuffer()) {
		return false;
	}
	if (_numOfComponent != attribute->getNumOfComponent()) {
		return false;
	}
	if (_componentDataType != attribute->getComponentDataType()) {
		return false;
	}
	if (_normalized != attribute->getNormalized()) {
		return false;
	}
	if (_strideInBytes != attribute->getStrideInBytes()) {
		return false;
	}
	if (_offsetInBytes != attribute->getOffsetInBytes()) {
		return false;
	}
	if (_dirty != attribute->getDirty()) {
		return false;
	}
	return true;
};
