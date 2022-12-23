
#include "clear_state.h"

using namespace qiao;

ClearState::ClearState() {
	_scissorTest = ScissorTest();
	_colorMask = ColorMask(true, true, true, true);
	_depthMask = DepthMask::TRUE;

	_clearMask = ClearMask::ALL;
	_color = Color::WHITE();
	_depth = 1.0;
	_stencil = 0;
}

ScissorTest& ClearState::getScissorTest() {
	return _scissorTest;
};

void ClearState::setScissorTest(ScissorTest val) {
	_scissorTest = val;
};

ColorMask& ClearState::getColorMask() {
	return _colorMask;
};

void ClearState::setColorMask(ColorMask val) {
	_colorMask = val;
};

DepthMask ClearState::getDepthMask() {
	return _depthMask;
};

void ClearState::setDepthMask(DepthMask val) {
	_depthMask = val;
};

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