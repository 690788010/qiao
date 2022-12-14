
#include <iostream>
#include "render_state.h"

using namespace qiao;

RenderState::RenderState() {
	_programPointSize = GL_FALSE;
	_polygonMode = PolygonMode::FILL;
}

PrimitiveRestart& RenderState::getPrimitiveRestart() {
	return _primitiveRestart;
};

void RenderState::setPrimitiveRestart(PrimitiveRestart& val) {
	_primitiveRestart = val;
};

CullFace& RenderState::getCullFace() {
	return _cullFace;
};

void RenderState::setCullFace(CullFace& val) {
	_cullFace = val;
};

GLboolean RenderState::getProgramPointSize() {
	return _programPointSize;
};

void RenderState::setProgramPointSize(GLboolean val) {
	_programPointSize = val;
};

ScissorTest& RenderState::getScissorTest() {
	return _scissorTest;
};

void RenderState::setScissorTest(ScissorTest& val) {
	_scissorTest = val;
};

PolygonMode& RenderState::getPolygonMode() {
	return _polygonMode;
};

void RenderState::setPolygonMode(PolygonMode val) {
	_polygonMode = val;
};

StencilTest& RenderState::getStencilTest() {
	return _stencilTest;
};

void RenderState::setStencilTest(StencilTest& val) {
	_stencilTest = val;
};

DepthTest& RenderState::getDepthTest() {
	return _depthTest;
};

void RenderState::setDepthTest(DepthTest& val) {
	_depthTest = val;
};

Blending& RenderState::getBlending() {
	return _blending;
};

void RenderState::setBlending(Blending& val) {
	_blending = val;
};

ColorMask& RenderState::getColorMask() {
	return _colorMask;
};

void RenderState::setColorMask(ColorMask& val) {
	_colorMask = val;
};