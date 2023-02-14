#include "vector4d.h"

using namespace qiao;

Vector4D Vector4D::Zero = Vector4D(0.0, 0.0, 0.0, 0.0);
Vector4D Vector4D::UnitX = Vector4D(1.0, 0.0, 0.0, 0.0);
Vector4D Vector4D::UnitY = Vector4D(0.0, 1.0, 0.0, 0.0);
Vector4D Vector4D::UnitZ = Vector4D(0.0, 0.0, 1.0, 0.0);
Vector4D Vector4D::UnitW = Vector4D(0.0, 0.0, 0.0, 1.0);

Vector4D::Vector4D(double x, double y, double z, double w) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_w = w;
};

double Vector4D::getX() {
	return _x;
};

double Vector4D::getY() {
	return _y;
};

double Vector4D::getZ() {
	return _z;
};

double Vector4D::getW() {
	return _w;
};

