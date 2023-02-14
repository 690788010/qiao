#include "camera.h"


using namespace qiao;

Camera::Camera() : _eye{ Vector3D(0.0, -1.0, 0.0) }, _target{ Vector3D::Zero }, _up{Vector3D::UnitZ} {
	_fieldOfViewY = M_PI / 6.0;
	_aspectRatio = 1.0;
}

Vector3D Camera::getEye() {
	return _eye;
};

void Camera::setEye(Vector3D eye) {
	_eye = eye;
};

Vector3D Camera::getTarget() {
	return _target;
};

void Camera::setTarget(Vector3D target) {
	_target = target;
};

Vector3D Camera::getUp() {
	return _up;
};

void Camera::setUp(Vector3D up) {
	_up = up;
};

double Camera::getFieldOfViewY() {
	return _fieldOfViewY;
};

void Camera::setFieldOfViewY(double fovy) {
	_fieldOfViewY = fovy;
};

double Camera::getAspectRatio() {
	return _aspectRatio;
};

void Camera::setAspectRatio(double ratio) {
	_aspectRatio = ratio;
};