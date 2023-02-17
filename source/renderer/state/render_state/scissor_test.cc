/**
 * @file scissor_test.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "scissor_test.h"

using namespace qiao;

ScissorTest::ScissorTest() : _enabled{ false }, _x{ 0 }, _y{ 0 }, _width{ 0 }, _height{ 0 } {};

bool ScissorTest::getEnabled() {
	return _enabled;
};

void ScissorTest::setEnabled(bool enabled) {
	_enabled = enabled;
};

int ScissorTest::getX() {
	return _x;
};

void ScissorTest::setX(int x) {
	_x = x;
};

int ScissorTest::getY() {
	return _y;
};

void ScissorTest::setY(int y) {
	_y = y;
};

int ScissorTest::getWidth() {
	return _width;
};

void ScissorTest::setWidth(int width) {
	_width = width;
};

int ScissorTest::getHeight() {
	return _height;
};

void ScissorTest::setHeight(int height) {
	_height = height;
};