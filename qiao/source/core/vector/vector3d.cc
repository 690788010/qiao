#include "vector3d.h"

using namespace qiao;

Vector3D Vector3D::Zero = Vector3D(0.0, 0.0, 0.0);
Vector3D Vector3D::UnitX = Vector3D(1.0, 0.0, 0.0);
Vector3D Vector3D::UnitY = Vector3D(0.0, 1.0, 0.0);
Vector3D Vector3D::UnitZ = Vector3D(0.0, 0.0, 1.0);

Vector3D::Vector3D(double x, double y, double z) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
};

