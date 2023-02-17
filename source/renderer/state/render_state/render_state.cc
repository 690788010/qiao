/**
 * @file render_state.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "render_state.h"

using namespace qiao;

RenderState::RenderState() {
	_programPointSize = GL_FALSE;
	_polygonMode = GL_FILL;
}

PrimitiveRestart& RenderState::getPrimitiveRestart() {
	return _primitiveRestart;
};

void RenderState::setPrimitiveRestart(PrimitiveRestart primitiveRestart) {
	_primitiveRestart = primitiveRestart;
};

CullFace& RenderState::getCullFace() {
	return _cullFace;
};

void RenderState::setCullFace(CullFace cullFace) {
	_cullFace = cullFace;
};

GLboolean RenderState::getProgramPointSize() {
	return _programPointSize;
};

void RenderState::setProgramPointSize(GLboolean programPointSize) {
	_programPointSize = programPointSize;
};

ScissorTest& RenderState::getScissorTest() {
	return _scissorTest;
};

void RenderState::setScissorTest(ScissorTest scissorTest) {
	_scissorTest = scissorTest;
};

GLenum RenderState::getPolygonMode() {
	return _polygonMode;
};

void RenderState::setPolygonMode(GLenum mode) {
	_polygonMode = mode;
};

StencilTest& RenderState::getStencilTest() {
	return _stencilTest;
};

void RenderState::setStencilTest(StencilTest stencilTest) {
	_stencilTest = stencilTest;
};

DepthTest& RenderState::getDepthTest() {
	return _depthTest;
};

void RenderState::setDepthTest(DepthTest depthTest) {
	_depthTest = depthTest;
};

Blending& RenderState::getBlending() {
	return _blending;
};

void RenderState::setBlending(Blending blending) {
	_blending = blending;
};

ColorMask& RenderState::getColorMask() {
	return _colorMask;
};

void RenderState::setColorMask(ColorMask colorMask) {
	_colorMask = colorMask;
};