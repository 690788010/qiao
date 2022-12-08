#include "indices_unsigned_short.h"

using namespace qiao;

GLenum IndicesUnsignedShort::getType() {
	return GL_UNSIGNED_SHORT;
};

size_t IndicesUnsignedShort::getSize() {
	return _values.size();
};

void IndicesUnsignedShort::addIndex(unsigned short index) {
	_values.push_back(index);
};

unsigned short IndicesUnsignedShort::getIndex(unsigned int idx) {
	return _values[idx];
};