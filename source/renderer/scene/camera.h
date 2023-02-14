#pragma once

#include "../../core/vector/vector3d.h"

namespace qiao {
	class Camera {
	public:
		Camera();

		Vector3D getEye();
		void setEye(Vector3D eye);

		Vector3D getTarget();
		void setTarget(Vector3D target);

		Vector3D getUp();
		void setUp(Vector3D up);

		double getFieldOfViewY();
		void setFieldOfViewY(double fovy);

		double getAspectRatio();
		void setAspectRatio(double ratio);

	private:
		Vector3D _eye;
		Vector3D _target;
		Vector3D _up;
		double _fieldOfViewY;
		double _aspectRatio;
	};
}
