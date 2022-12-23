
#include "stencil_test.h"

using namespace qiao;

StencilTest::StencilTest() {
	_enabled = false;
};

bool StencilTest::getEnabled() {
	return _enabled;
};

void StencilTest::setEnabled(bool val) {
	_enabled = val;
};