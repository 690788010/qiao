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

	private:
		Camera* _camera;
		Matrix4D _modelMatrix;
	};
}