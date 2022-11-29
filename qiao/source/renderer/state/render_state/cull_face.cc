
#include "cull_face.h"

using namespace qiao;

CullFace::CullFace() {
	enabled = true;
	cullFaceMode = CullFaceMode::BACK;
	frontFaceMode = FrontFaceMode::CCW;
};

bool CullFace::getEnabled() {
	return enabled;
};
void CullFace::setEnabled(bool val) {
	enabled = val;
};

CullFaceMode CullFace::getCullFaceMode() {
	return cullFaceMode;
};

void CullFace::setCullFaceMode(CullFaceMode val) {
	cullFaceMode = val;
};

FrontFaceMode CullFace::getFrontFaceMode() {
	return frontFaceMode;
};

void CullFace::setFrontFaceMode(FrontFaceMode val) {
	frontFaceMode = val;
};