#include "index_buffer_gl3x.h"

using namespace qiao;

IndexBufferGL3x::IndexBufferGL3x(GLenum usage, GLsizeiptr sizeInBytes) {
	_bufferGL3x = new BufferGL3x(GL_ELEMENT_ARRAY_BUFFER, usage, sizeInBytes);
};

IndexBufferGL3x::~IndexBufferGL3x() {
	if (_bufferGL3x != nullptr) {
		delete _bufferGL3x;
		_bufferGL3x = nullptr;
	}
};

void IndexBufferGL3x::bind() {
	_bufferGL3x->bind();
};

void IndexBufferGL3x::unBind() {
	_bufferGL3x->unBind();
};

void IndexBufferGL3x::copyFromSystemMemory(void* data, IndexBufferDataType dataType, unsigned int offset, unsigned int size) {
	int typeSize = 0;
	if (dataType == IndexBufferDataType::UNSIGNED_BYTE) {
		_dataType = GL_UNSIGNED_BYTE;
		typeSize = 0;
	}
	else if (dataType == IndexBufferDataType::UNSIGNED_SHORT) {
		_dataType = GL_UNSIGNED_SHORT;
		typeSize = 2;
	}
	else if (dataType == IndexBufferDataType::UNSIGNED_INT) {
		_dataType = GL_UNSIGNED_INT;
		typeSize = 4;
	}
	else {
		throw std::invalid_argument("argument dataType is incorrect!");
	}
	_count = _bufferGL3x->getSizeInBytes() / typeSize;
	_bufferGL3x->copyFromSystemMemory(data, offset, size);
};

void IndexBufferGL3x::copyToSystemMemory(void* data, unsigned int offset, unsigned int size) {
	_bufferGL3x->copyToSystemMemory(data, offset, size);
};

unsigned int IndexBufferGL3x::getUsage() {
	return _bufferGL3x->getUsage();
};

unsigned int IndexBufferGL3x::getSizeInBytes() {
	return _bufferGL3x->getSizeInBytes();
};

unsigned int IndexBufferGL3x::getDataType() {
	return  _dataType;
};