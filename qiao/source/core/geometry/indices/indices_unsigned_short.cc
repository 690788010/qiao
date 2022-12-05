#include "indices_unsigned_short.h"

using namespace qiao;

GLenum IndicesUnsignedShort::getType() {
	return GL_UNSIGNED_SHORT;
};

void IndicesUnsignedShort::addIndex(unsigned short index) {
	_values.push_back(index);
};