#pragma once
#include "camera.h"
#include "../../core/matrix/matrix4d.h"

namespace qiao {
	class SceneState {
	public:
		SceneState();
		~SceneState();

		Camera* getCamera();
		void setCamera(Camera* camera);

		Matrix4D& getModelMatrix();
		void setModelMatrix(const Matrix4D& mat4);

	private:
		Camera* _camera;
		Matrix4D _modelMatrix;
	};
}