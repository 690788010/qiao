#pragma once

namespace qiao {
	class Vector4F {
	public:
		Vector4F(float x, float y, float z, float w);

		static Vector4F Zero;
		static Vector4F UnitX;
		static Vector4F UnitY;
		static Vector4F UnitZ;
		static Vector4F UnitW;

		float getX();
		float getY();
		float getZ();
		float getW();

	private:
		float _x;
		float _y;
		float _z;
		float _w;
	};
}