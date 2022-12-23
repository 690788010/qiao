
#include "depth_test.h"

using namespace qiao;

DepthTest::DepthTest() {
	enabled = true;
	depthFunc = DepthFunc::LESS;
	depthMask = GL_TRUE;
	near = 0.0;
	far = 1.0;
};

bool DepthTest::getEnabled() {
	return enabled;
};

void DepthTest::setEnabled(bool val) {
	enabled = val;
};

DepthFunc DepthTest::getDepthFunc() {
	return depthFunc;
};

void DepthTest::setDepthFunc(DepthFunc val) {
	depthFunc = val;
};

GLboolean DepthTest::getDepthMask() {
	return depthMask;
};

void DepthTest::setDepthMask(GLboolean val) {
	depthMask = val;
};

double DepthTest::getNear() {
	return near;
};
void DepthTest::setNear(double val) {
	near = val;
};

double DepthTest::getFar() {
	return far;
};
void DepthTest::setFar(double val) {
	far = val;
};