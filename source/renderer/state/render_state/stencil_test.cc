/**
 * @file stencil_test.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "stencil_test.h"

using namespace qiao;

StencilTest::StencilTest() : _enabled{ false } {};

bool StencilTest::getEnabled() {
	return _enabled;
};

void StencilTest::setEnabled(bool enabled) {
	_enabled = enabled;
};