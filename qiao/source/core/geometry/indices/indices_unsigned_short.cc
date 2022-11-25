#include "indices_unsigned_short.h"

using namespace qiao;

GLenum IndicesUnsignedShort::getDataType() {
	return GL_UNSIGNED_INT;
};

void IndicesUnsignedShort::addIndex(unsigned short index) {
	_values.push_back(index);
};