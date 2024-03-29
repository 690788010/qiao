/**
 * @file clear_state.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "clear_state.h"

using namespace qiao;

ClearState::ClearState() {
	_clearMask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT;
	_color = Color::WHITE;
	_depth = 1.0;
	_stencil = 0;

	_scissorTest = ScissorTest();
	_colorMask = ColorMask(true, true, true, true);
	_depthMask = GL_TRUE;
}

GLbitfield ClearState::getClearMask() {
	return _clearMask;
};

void ClearState::setClearMask(GLbitfield val) {
	_clearMask = val;
};

Color& ClearState::getColor() {
	return _color;
};

void ClearState::setColor(Color val) {
	_color = val;
};

double ClearState::getDepth() {
	return _depth;
};

void ClearState::setDepth(double val) {
	_depth = val;
};

int ClearState::getStencil() {
	return _stencil;
};

void ClearState::setStencil(int val) {
	_stencil = val;
};

ColorMask& ClearState::getColorMask() {
	return _colorMask;
};

void ClearState::setColorMask(ColorMask colorMask) {
	_colorMask = colorMask;
};

GLboolean ClearState::getDepthMask() {
	return _depthMask;
};

void ClearState::setDepthMask(GLboolean flag) {
	_depthMask = flag;
};

ScissorTest& ClearState::getScissorTest() {
	return _scissorTest;
};

void ClearState::setScissorTest(ScissorTest scissorTest) {
	_scissorTest = scissorTest;
};