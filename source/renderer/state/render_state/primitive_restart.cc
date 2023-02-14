
#include "primitive_restart.h"

using namespace qiao;

PrimitiveRestart::PrimitiveRestart() : enabled(false), index(0) {}

bool PrimitiveRestart::getEnabled() {
	return enabled;
}

void PrimitiveRestart::setEnabled(bool val) {
	enabled = val;
}

int PrimitiveRestart::getIndex() {
	return index;
}

void PrimitiveRestart::setIndex(int val) {
	index = val;
};