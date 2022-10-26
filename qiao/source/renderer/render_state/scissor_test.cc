
#include "scissor_test.h"

using namespace qiao;

Rectangle::Rectangle(int x, int y, int width, int height) : 
	x{ x }, y{ y }, width{ width }, height{ height } {};

int Rectangle::getX() {
	return x;
};

int Rectangle::getY() {
	return y;
};

int Rectangle::getWidth() {
	return width;
};
int Rectangle::getHeight() {
	return height;
};

ScissorTest::ScissorTest() : enabled{ false }, rectangle{ Rectangle(0, 0, 0, 0) } {};

bool ScissorTest::getEnabled() {
	return enabled;
};
void ScissorTest::setEnabled(bool val) {
	enabled = val;
};

Rectangle& ScissorTest::getRectangle() {
	return rectangle;
};

void ScissorTest::setRectangle(Rectangle val) {
	rectangle = val;
};