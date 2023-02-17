/**
 * @file cull_face.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "cull_face.h"

using namespace qiao;

CullFace::CullFace() {
	_enabled = true;
	_cullFaceMode = GL_BACK;
	_frontFaceMode = GL_CCW;
};

bool CullFace::getEnabled() {
	return _enabled;
};

void CullFace::setEnabled(bool enabled) {
	_enabled = enabled;
};

GLenum CullFace::getCullFaceMode() {
	return _cullFaceMode;
};

void CullFace::setCullFaceMode(GLenum mode) {
	_cullFaceMode = mode;
};

GLenum CullFace::getFrontFaceMode() {
	return _frontFaceMode;
};

void CullFace::setFrontFaceMode(GLenum mode) {
	_frontFaceMode = mode;
};