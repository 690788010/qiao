
#include "depth_test.h"

using namespace qiao;

DepthTest::DepthTest() {
	_enabled = true;
	_depthFunc = DepthFunc::LESS;
	_depthMask = GL_TRUE;
	_near = 0.0;
	_far = 1.0;
};

bool DepthTest::getEnabled() {
	return _enabled;
};

void DepthTest::setEnabled(bool val) {
	_enabled = val;
};

DepthFunc DepthTest::getDepthFunc() {
	return _depthFunc;
};

void DepthTest::setDepthFunc(DepthFunc val) {
	_depthFunc = val;
};

GLboolean DepthTest::getDepthMask() {
	return _depthMask;
};

void DepthTest::setDepthMask(GLboolean val) {
	_depthMask = val;
};

double DepthTest::getNear() {
	return _near;
};
void DepthTest::setNear(double val) {
	_near = val;
};

double DepthTest::getFar() {
	return _far;
};
void DepthTest::setFar(double val) {
	_far = val;
};