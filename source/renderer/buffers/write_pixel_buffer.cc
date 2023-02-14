#include "write_pixel_buffer.h"

using namespace qiao;

WritePixelBuffer::WritePixelBuffer(GLenum usage, GLsizeiptr sizeInBytes) {
	_buffer = new Buffer(GL_PIXEL_UNPACK_BUFFER, usage, sizeInBytes);
};

WritePixelBuffer::~WritePixelBuffer() {
	if (_buffer != nullptr) {
		delete _buffer;
		_buffer = nullptr;
	}
};

// 将数据从系统内存复制到GPU显存
void WritePixelBuffer::copyFromSystemMemory(void* data, unsigned int offset, unsigned int size) {
	_buffer->copyFromSystemMemory(data, offset, size);
};

// 将数据从GPU显存复制到系统内存
void WritePixelBuffer::copyToSystemMemory(void* data, unsigned int offset, unsigned int size) {
	_buffer->copyToSystemMemory(data, offset, size);
};

void WritePixelBuffer::bind() {
	_buffer->bind();
};

void WritePixelBuffer::unBind() {
	_buffer->unBind();
};

GLenum WritePixelBuffer::getUsage() {
	return _buffer->getUsage();
};

GLsizeiptr WritePixelBuffer::getSizeInBytes() {
	return _buffer->getSizeInBytes();
};
