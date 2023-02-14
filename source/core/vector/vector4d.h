#pragma once

namespace qiao {
	class Vector4D {
	public:
		Vector4D(double x, double y, double z, double w);

		static Vector4D Zero;
		static Vector4D UnitX;
		static Vector4D UnitY;
		static Vector4D UnitZ;
		static Vector4D UnitW;

		double getX();
		double getY();
		double getZ();
		double getW();

	private:
		double _x;
		double _y;
		double _z;
		double _w;
	};
}