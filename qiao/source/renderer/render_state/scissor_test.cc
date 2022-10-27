
#include "scissor_test.h"

using namespace qiao;

ScissorTest::ScissorTest() : enabled{ false }, x{ 0 }, y{ 0 }, width{ x }, height{ 0 } {};

bool ScissorTest::getEnabled() {
	return enabled;
};
void ScissorTest::setEnabled(bool val) {
	enabled = val;
};

int ScissorTest::getX() {
	return x;
};

int ScissorTest::getY() {
	return y;
};

int ScissorTest::getWidth() {
	return width;
};
int ScissorTest::getHeight() {
	return height;
};