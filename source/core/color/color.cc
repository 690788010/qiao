/**
 * @file color.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "color.h"

using namespace qiao;

Color Color::WHITE = Color(1.0, 1.0, 1.0, 1.0);
Color Color::BLACK = Color(0.0, 0.0, 0.0, 1.0);

Color::Color() {
	this->_red = 1.0;
	this->_green = 1.0;
	this->_blue = 1.0;
	this->_alpha = 1.0;
};

Color::Color(double red, double green, double blue, double alpha) {
	this->_red = red;
	this->_green = green;
	this->_blue = blue;
	this->_alpha = alpha;
};

double Color::getRed() const {
	return _red;
};

void Color::setRed(double val) {
	_red = val;
};

double Color::getGreen() const {
	return _green;
};

void Color::setGreen(double val) {
	_green = val;
};

double Color::getBlue() const {
	return _blue;
};

void Color::setBlue(double val) {
	_blue = val;
};

double Color::getAlpha() const {
	return _alpha;
};

void Color::setAlpha(double val) {
	_alpha = val;
};

bool Color::operator==(Color& color) const {
	if (_red != color.getRed()) {
		return false;
	}
	if (_green != color.getGreen()) {
		return false;
	}
	if (_blue != color.getBlue()) {
		return false;
	}
	if (_alpha != color.getAlpha()) {
		return false;
	}
	return true;
};

bool Color::operator!=(Color& color) const {
	if (_red != color.getRed()) {
		return true;
	}
	if (_green != color.getGreen()) {
		return true;
	}
	if (_blue != color.getBlue()) {
		return true;
	}
	if (_alpha != color.getAlpha()) {
		return true;
	}
	return false;
};
