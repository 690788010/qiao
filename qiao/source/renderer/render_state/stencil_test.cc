
#include "stencil_test.h"

using namespace qiao;

StencilTest::StencilTest() {
	enabled = false;
};

bool StencilTest::getEnabled() {
	return enabled;
};

void StencilTest::setEnabled(bool val) {
	enabled = val;
};