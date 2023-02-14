
#include "cull_face.h"

using namespace qiao;

CullFace::CullFace() {
	_enabled = true;
	_cullFaceMode = CullFaceMode::BACK;
	_frontFaceMode = FrontFaceMode::CCW;
};

bool CullFace::getEnabled() {
	return _enabled;
};
void CullFace::setEnabled(bool val) {
	_enabled = val;
};

CullFaceMode CullFace::getCullFaceMode() {
	return _cullFaceMode;
};

void CullFace::setCullFaceMode(CullFaceMode val) {
	_cullFaceMode = val;
};

FrontFaceMode CullFace::getFrontFaceMode() {
	return _frontFaceMode;
};

void CullFace::setFrontFaceMode(FrontFaceMode val) {
	_frontFaceMode = val;
};