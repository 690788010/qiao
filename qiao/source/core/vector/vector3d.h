#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace qiao {
	class Vector3D {
	public:
		Vector3D(double x, double y, double z);

		static Vector3D Zero;
		static Vector3D UnitX;
		static Vector3D UnitY;
		static Vector3D UnitZ;

	private:
		double _x;
		double _y;
		double _z;
	};
}