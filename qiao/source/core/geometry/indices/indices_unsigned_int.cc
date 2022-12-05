#include "indices_unsigned_int.h"

using namespace qiao;

GLenum IndicesUnsignedInt::getType() {
	return GL_UNSIGNED_INT;
};

void IndicesUnsignedInt::addIndex(unsigned int index) {
	_values.push_back(index);
};