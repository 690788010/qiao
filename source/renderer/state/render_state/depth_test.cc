/**
 * @file depth_test.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */


#include "depth_test.h"

using namespace qiao;

DepthTest::DepthTest() {
	_enabled = true;
	_depthFunc = GL_LESS;
	_depthMask = GL_TRUE;
	_near = 0.0;
	_far = 1.0;
};

bool DepthTest::getEnabled() {
	return _enabled;
};

void DepthTest::setEnabled(bool enabled) {
	_enabled = enabled;
};

GLenum DepthTest::getDepthFunc() {
	return _depthFunc;
};

void DepthTest::setDepthFunc(GLenum func) {
	_depthFunc = func;
};

GLboolean DepthTest::getDepthMask() {
	return _depthMask;
};

void DepthTest::setDepthMask(GLboolean flag) {
	_depthMask = flag;
};

double DepthTest::getNear() {
	return _near;
};
void DepthTest::setNear(double near) {
	_near = near;
};

double DepthTest::getFar() {
	return _far;
};
void DepthTest::setFar(double far) {
	_far = far;
};