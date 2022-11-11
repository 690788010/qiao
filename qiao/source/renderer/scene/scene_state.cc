#include "scene_state.h"

using namespace qiao;

SceneState::SceneState() {
	_camera = new Camera();
}

SceneState::~SceneState() {
	if (_camera != nullptr) {
		delete _camera;
		_camera = nullptr;
	}
}

Camera* SceneState::getCamera() {
	return _camera;
};

void SceneState::setCamera(Camera* camera) {
	_camera = camera;
};