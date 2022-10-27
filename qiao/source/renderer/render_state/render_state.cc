
#include "render_state.h"

using namespace qiao;

RenderState::RenderState() {
	primitiveRestart = PrimitiveRestart();
	cullFace = CullFace();
	programPointSize = ProgramPointSize::Disabled;
	scissorTest = ScissorTest();
	polygonMode = PolygonMode::FILL;
	depthTest = DepthTest();
}

PrimitiveRestart& RenderState::getPrimitiveRestart() {
	return primitiveRestart;
};

void RenderState::setPrimitiveRestart(PrimitiveRestart val) {
	primitiveRestart = val;
};

CullFace& RenderState::getCullFace() {
	return cullFace;
};

void RenderState::setCullFace(CullFace val) {
	cullFace = val;
};

ProgramPointSize RenderState::getProgramPointSize() {
	return programPointSize;
};

void RenderState::setProgramPointSize(ProgramPointSize val) {
	programPointSize = val;
};

ScissorTest& RenderState::getScissorTest() {
	return scissorTest;
};

void RenderState::setScissorTest(ScissorTest val) {
	scissorTest = val;
};

PolygonMode& RenderState::getPolygonMode() {
	return polygonMode;
};

void RenderState::setPolygonMode(PolygonMode val) {
	polygonMode = val;
};

StencilTest& RenderState::getStencilTest() {
	return stencilTest;
};

void RenderState::setStencilTest(StencilTest val) {
	stencilTest = val;
};

DepthTest& RenderState::getDepthTest() {
	return depthTest;
};

void RenderState::setDepthTest(DepthTest val) {
	depthTest = val;
};

Blending& RenderState::getBlending() {
	return blending;
};

void RenderState::setBlending(Blending val) {
	blending = val;
};