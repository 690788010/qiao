/**
 * @file primitive_restart.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "primitive_restart.h"

using namespace qiao;

PrimitiveRestart::PrimitiveRestart() : _enabled(false), _index(0) {}

bool PrimitiveRestart::getEnabled() {
	return _enabled;
}

void PrimitiveRestart::setEnabled(bool enabled) {
	_enabled = enabled;
}

int PrimitiveRestart::getIndex() {
	return _index;
}

void PrimitiveRestart::setIndex(int index) {
	_index = index;
};