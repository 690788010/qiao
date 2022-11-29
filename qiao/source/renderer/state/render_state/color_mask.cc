
#include "./color_mask.h"

using namespace qiao;

ColorMask::ColorMask() {}

ColorMask::ColorMask(bool red, bool green, bool blue, bool alpha) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
};

bool ColorMask::getRed() {
	return red;
};

void ColorMask::setRed(bool val) {
	red = val;
};

bool ColorMask::getGreen() {
	return green;
};

void ColorMask::setGreen(bool val) {
	green = val;
};

bool ColorMask::getBlue() {
	return blue;
};

void ColorMask::setBlue(bool val) {
	blue = val;
};

bool ColorMask::getAlpha() {
	return alpha;
};

void ColorMask::setAlpha(bool val) {
	alpha = val;
};

bool ColorMask::equals(ColorMask obj) {
	if (red != obj.getRed()) {
		return false;
	}
	if (green != obj.getGreen()) {
		return false;
	}
	if (blue != obj.getBlue()) {
		return false;
	}
	if (alpha != obj.getAlpha()) {
		return false;
	}
	return true;
};