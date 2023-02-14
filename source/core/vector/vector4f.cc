#include "vector4f.h"

using namespace qiao;

Vector4F Vector4F::Zero = Vector4F(0.0, 0.0, 0.0, 0.0);
Vector4F Vector4F::UnitX = Vector4F(1.0, 0.0, 0.0, 0.0);
Vector4F Vector4F::UnitY = Vector4F(0.0, 1.0, 0.0, 0.0);
Vector4F Vector4F::UnitZ = Vector4F(0.0, 0.0, 1.0, 0.0);
Vector4F Vector4F::UnitW = Vector4F(0.0, 0.0, 0.0, 1.0);

Vector4F::Vector4F(float x, float y, float z, float w) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_w = w;
};

float Vector4F::getX() {
	return _x;
};

float Vector4F::getY() {
	return _y;
};

float Vector4F::getZ() {
	return _z;
};

float Vector4F::getW() {
	return _w;
};

