#include "indices_unsigned_int.h"

using namespace qiao;

GLenum IndicesUnsignedInt::getType() {
	return GL_UNSIGNED_INT;
};

size_t IndicesUnsignedInt::getSize() {
	return _values.size();
};

void IndicesUnsignedInt::addIndex(unsigned int index) {
	_values.push_back(index);
};

unsigned int IndicesUnsignedInt::getIndex(unsigned int idx) {
	return _values[idx];
};

