
#include "Color.h"

using namespace qiao;

Color::Color() {};
Color::Color(double red, double green, double blue, double alpha) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
};

double Color::getRed() {
	return red;
};

void Color::setRed(double val) {
	red = val;
};

double Color::getGreen() {
	return green;
};

void Color::setGreen(double val) {
	green = val;
};

double Color::getBlue() {
	return blue;
};

void Color::setBlue(double val) {
	blue = val;
};

double Color::getAlpha() {
	return alpha;
};

void Color::setAlpha(double val) {
	alpha = val;
};

bool Color::equals(Color color) {
	if (red != color.getRed()) {
		return false;
	}
	if (green != color.getGreen()) {
		return false;
	}
	if (blue != color.getBlue()) {
		return false;
	}
	if (alpha != color.getAlpha()) {
		return false;
	}
	return true;
};

Color Color::White() {
	return Color(1.0, 1.0, 1.0, 1.0);
};