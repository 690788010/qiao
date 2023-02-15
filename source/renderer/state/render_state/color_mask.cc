/**
 * @file color_mask.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "./color_mask.h"

using namespace qiao;

ColorMask::ColorMask() : ColorMask (true, true, true, true) {}

ColorMask::ColorMask(bool red, bool green, bool blue, bool alpha) 
	: _red{ red }, _green{ green }, _blue{ blue }, _alpha {alpha} {};

bool ColorMask::getRed() {
	return _red;
};

void ColorMask::setRed(bool red) {
	_red = red;
};

bool ColorMask::getGreen() {
	return _green;
};

void ColorMask::setGreen(bool green) {
	_green = green;
};

bool ColorMask::getBlue() {
	return _blue;
};

void ColorMask::setBlue(bool blue) {
	_blue = blue;
};

bool ColorMask::getAlpha() {
	return _alpha;
};

void ColorMask::setAlpha(bool alpha) {
	_alpha = alpha;
};

bool ColorMask::operator==(ColorMask& colorMask) const {
	if (_red != colorMask._red) {
		return false;
	}
	if (_green != colorMask._green) {
		return false;
	}
	if (_blue != colorMask._blue) {
		return false;
	}
	if (_alpha != colorMask._alpha) {
		return false;
	}
	return true;
};

bool ColorMask::operator!=(ColorMask& colorMask) const {
	if (_red != colorMask._red) {
		return true;
	}
	if (_green != colorMask._green) {
		return true;
	}
	if (_blue != colorMask._blue) {
		return true;
	}
	if (_alpha != colorMask._alpha) {
		return true;
	}
	return false;
};
