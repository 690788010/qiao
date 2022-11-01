
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

void ScissorTest::setX(int val) {
	x = val;
};

int ScissorTest::getY() {
	return y;
};

void ScissorTest::setY(int val) {
	y = val;
};

int ScissorTest::getWidth() {
	return width;
};

void ScissorTest::setWidth(int val) {
	width = val;
};

int ScissorTest::getHeight() {
	return height;
};

void ScissorTest::setHeight(int val) {
	height = val;
};