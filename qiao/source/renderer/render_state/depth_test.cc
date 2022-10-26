
#include "depth_test.h"

using namespace qiao;

DepthRange::DepthRange(double near, double far) {
	this->near = near;
	this->far = far;
};

double DepthRange::getNear() {
	return near;
};
void DepthRange::setNear(double val) {
	near = val;
};

double DepthRange::getFar() {
	return far;
};

void DepthRange::setFar(double val) {
	far = val;
};

DepthTest::DepthTest() {
	enabled = true;
	depthFunc = DepthFunc::LESS;
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

DepthRange& DepthTest::getDepthRange() {
	return depthRange;
};

void DepthTest::setDepthRange(DepthRange val) {
	depthRange = val;
};

bool DepthTest::getDepthMask() {
	return depthMask;
};

void DepthTest::setDepthMask(bool val) {
	depthMask = val;
};