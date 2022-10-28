
#include <stdexcept>

#include "context_gl3x.h"

using namespace qiao;

ContextGL3x::ContextGL3x() {
	_renderState = new RenderState();

	// Sync GL state with default render state.
	syncRenderState(_renderState);
}

ContextGL3x::~ContextGL3x() {
	if (_renderState != nullptr) {
		delete _renderState;
		_renderState = nullptr;
	}
}

//void ContextGL3x::draw(DrawState* drawState) {
//	verifyDraw(drawState);
//
//};

void ContextGL3x::syncRenderState(RenderState* renderState) {
	PrimitiveRestart primitiveRestart = renderState->getPrimitiveRestart();
	enable(GL_PRIMITIVE_RESTART, primitiveRestart.getEnabled());
	glPrimitiveRestartIndex(primitiveRestart.getIndex());

	CullFace cullFace = renderState->getCullFace();
	enable(GL_CULL_FACE, cullFace.getEnabled());
	glFrontFace(cullFace.getFrontFaceMode());
	glCullFace(cullFace.getCullFaceMode());

	enable(GL_PROGRAM_POINT_SIZE, renderState->getProgramPointSize());

	glPolygonMode(GL_FRONT_AND_BACK, renderState->getPolygonMode());

	ScissorTest scissorTest = renderState->getScissorTest();
	enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
	glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());

	DepthTest depthTest = renderState->getDepthTest();
	enable(GL_DEPTH_TEST, depthTest.getEnabled());
	glDepthFunc(depthTest.getDepthFunc());
	glDepthMask(depthTest.getDepthMask());
	glDepthRange(depthTest.getNear(), depthTest.getFar());

	Blending blending = renderState->getBlending();
	enable(GL_BLEND, blending.getEnabled());
	glBlendFuncSeparate(blending.getSrcRGB(), blending.getDstRGB(), blending.getSrcAlpha(), blending.getDstAlpha());
	glBlendEquationSeparate(blending.getRgbEquation(), blending.getAlphaEquation());
};

// enable or disable server-side GL capabilities
void ContextGL3x::enable(GLenum cap, bool enabled) {
	if (enabled) {
		glEnable(cap);
	} else {
		glDisable(cap);
	}
};

void ContextGL3x::verifyDraw(DrawState* drawState) {
	if (drawState == nullptr) {
		throw std::invalid_argument("argument drawState is null!");
	}

	if (drawState->getRenderState() == nullptr) {
		throw  std::invalid_argument("drawState.renderState is null!");
	}
};

void ContextGL3x::applyBeforeDraw(DrawState* drawState) {
	applyRenderState(drawState->getRenderState());
};

void ContextGL3x::applyRenderState(RenderState* renderState) {
	// applyPrimitiveRestart
	PrimitiveRestart primitiveRestart = renderState->getPrimitiveRestart();
	PrimitiveRestart _primitiveRestart = _renderState->getPrimitiveRestart();
	if (primitiveRestart.getEnabled() != _primitiveRestart.getEnabled()) {
		enable(GL_PRIMITIVE_RESTART, primitiveRestart.getEnabled());
		_primitiveRestart.setEnabled(primitiveRestart.getEnabled());
	}


};