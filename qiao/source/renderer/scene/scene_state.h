#pragma once
#include "camera.h"

namespace qiao {
	class SceneState {
	public:
		SceneState();
		~SceneState();

		Camera* getCamera();
		void setCamera(Camera* camera);

	private:
		Camera* _camera;
	};
}