
#include <iostream>
#include <stdexcept>
#include "context_gl3x.h"
#include "shaders/shader_program_gl3x.h"


using namespace qiao;

ContextGL3x::ContextGL3x() {
	std::cout << "ContextGL3x()" << std::endl;

	_clearColor = Color::White();
	_clearDepth = 1.0;
	_clearStencil = 0;

	_renderState = new RenderState();

	// Sync GL state with default render state.
	syncRenderState(_renderState);
}

ContextGL3x::~ContextGL3x() {
	std::cout << "~ContextGL3x()" << std::endl;
	if (_renderState != nullptr) {
		delete _renderState;
		_renderState = nullptr;
	}
}

void ContextGL3x::clear(ClearState* clearState) {
	// apply ScissorTest
	ScissorTest scissorTest = clearState->getScissorTest();
	ScissorTest _scissorTest = _renderState->getScissorTest();
	if (scissorTest.getWidth() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Width must be greater than or equal to zero!");
	}
	if (scissorTest.getHeight() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Height must be greater than or equal to zero!");
	}
	if (scissorTest.getEnabled() != _scissorTest.getEnabled()) {
		enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
		_scissorTest.setEnabled(scissorTest.getEnabled());
	}
	if (scissorTest.getEnabled()) {
		if (scissorTest.getX() != _scissorTest.getX() ||
			scissorTest.getY() != _scissorTest.getY() ||
			scissorTest.getWidth() != _scissorTest.getWidth() ||
			scissorTest.getHeight() != _scissorTest.getHeight()) {
			glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());
			_scissorTest.setX(scissorTest.getX());
			_scissorTest.setY(scissorTest.getY());
			_scissorTest.setWidth(scissorTest.getWidth());
			_scissorTest.setHeight(scissorTest.getHeight());
		}
	}

	// apply ColorMask
	ColorMask colorMask = clearState->getColorMask();
	ColorMask _colorMask = _renderState->getColorMask();
	if (!colorMask.equals(_colorMask)) {
		glColorMask(colorMask.getRed(), colorMask.getGreen(), colorMask.getBlue(), colorMask.getAlpha());
		_renderState->setColorMask(colorMask);
	}

	// apply DepthMask
	if (clearState->getDepthMask() != _renderState->getDepthTest().getDepthMask()) {
		glDepthMask(clearState->getDepthMask());
		_renderState->getDepthTest().setDepthMask(clearState->getDepthMask());
	}

	// apply clearColor
	Color color = clearState->getColor();
	if (!color.equals(_clearColor)) {
		glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
		_clearColor = color;
	}

	// apply clearDepth
	if (clearState->getDepth() != _clearDepth) {
		glClearDepth(clearState->getDepth());
		_clearDepth = clearState->getDepth();
	}

	// apply clearStencil
	if (clearState->getStencil() != _clearStencil) {
		glClearStencil(clearState->getStencil());
		_clearStencil = clearState->getStencil();
	}

	glClear(clearState->getClearMask());
};

void ContextGL3x::draw(DrawState* drawState, SceneState* sceneState) {
	verifyDraw(drawState, sceneState);
	applyBeforeDraw(drawState, sceneState);
};

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

void ContextGL3x::enable(GLenum cap, bool enabled) {
	if (enabled) {
		glEnable(cap);
	} else {
		glDisable(cap);
	}
};

void ContextGL3x::verifyDraw(DrawState* drawState, SceneState* sceneState) {
	if (drawState == nullptr) {
		throw std::invalid_argument("argument drawState is null!");
	}

	if (drawState->getRenderState() == nullptr) {
		throw std::invalid_argument("drawState.renderState is null!");
	}

	if (drawState->getShaderProgram() == nullptr) {
		throw std::invalid_argument("drawState.shaderProgram is null!");
	}

	if (sceneState == nullptr) {
		throw std::invalid_argument("sceneState is null!");
	}
};

void ContextGL3x::applyBeforeDraw(DrawState* drawState, SceneState* sceneState) {
	applyRenderState(drawState->getRenderState());
	// ApplyVertexArray
	applyShaderProgram(drawState, sceneState);
};

void ContextGL3x::applyRenderState(RenderState* renderState) {
	// apply PrimitiveRestart
	PrimitiveRestart primitiveRestart = renderState->getPrimitiveRestart();
	PrimitiveRestart _primitiveRestart = _renderState->getPrimitiveRestart();
	if (primitiveRestart.getEnabled() != _primitiveRestart.getEnabled()) {
		enable(GL_PRIMITIVE_RESTART, primitiveRestart.getEnabled());
		_primitiveRestart.setEnabled(primitiveRestart.getEnabled());
	}

	// apply CullFace
	CullFace cullFace = renderState->getCullFace();
	CullFace _cullFace = _renderState->getCullFace();
	if (cullFace.getEnabled() != _cullFace.getEnabled()) {
		enable(GL_CULL_FACE, cullFace.getEnabled());
		_cullFace.setEnabled(cullFace.getEnabled());
	}
	if (cullFace.getEnabled()) {
		if (cullFace.getCullFaceMode() != _cullFace.getCullFaceMode()) {
			glCullFace(cullFace.getCullFaceMode());
			_cullFace.setCullFaceMode(cullFace.getCullFaceMode());
		}
		if (cullFace.getFrontFaceMode() != _cullFace.getFrontFaceMode()) {
			glFrontFace(cullFace.getFrontFaceMode());
			_cullFace.setFrontFaceMode(cullFace.getFrontFaceMode());
		}
	}

	// apply ProgramPointSize
	if (renderState->getProgramPointSize() != _renderState->getProgramPointSize()) {
		enable(GL_PROGRAM_POINT_SIZE, renderState->getProgramPointSize());
		_renderState->setProgramPointSize(renderState->getProgramPointSize());
	}

	// apply PolygonMode
	if (renderState->getPolygonMode() != _renderState->getPolygonMode()) {
		glPolygonMode(GL_FRONT_AND_BACK, renderState->getPolygonMode());
		_renderState->setPolygonMode(renderState->getPolygonMode());
	}

	// apply ScissorTest
	ScissorTest scissorTest = renderState->getScissorTest();
	ScissorTest _scissorTest = _renderState->getScissorTest();
	if (scissorTest.getWidth() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Width must be greater than or equal to zero!");
	}
	if (scissorTest.getHeight() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Height must be greater than or equal to zero!");
	}
	if (scissorTest.getEnabled() != _scissorTest.getEnabled()) {
		enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
		_scissorTest.setEnabled(scissorTest.getEnabled());
	}
	if (scissorTest.getEnabled()) {
		if (scissorTest.getX() != _scissorTest.getX() ||
			scissorTest.getY() != _scissorTest.getY() ||
			scissorTest.getWidth() != _scissorTest.getWidth() ||
			scissorTest.getHeight() != _scissorTest.getHeight()) {
			glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());
			_scissorTest.setX(scissorTest.getX());
			_scissorTest.setY(scissorTest.getY());
			_scissorTest.setWidth(scissorTest.getWidth());
			_scissorTest.setHeight(scissorTest.getHeight());
		}
	}

	// apply StencilTest
	StencilTest stencilTest = renderState->getStencilTest();
	StencilTest _stencilTest = _renderState->getStencilTest();
	if (stencilTest.getEnabled() != _stencilTest.getEnabled()) {
		enable(GL_STENCIL_TEST, stencilTest.getEnabled());
		_stencilTest.setEnabled(stencilTest.getEnabled());
	}

	// apply DepthTest
	DepthTest depthTest = renderState->getDepthTest();
	DepthTest _depthTest = _renderState->getDepthTest();
	if (depthTest.getEnabled() != _depthTest.getEnabled()) {
		enable(GL_DEPTH_TEST, depthTest.getEnabled());
		_depthTest.setEnabled(depthTest.getEnabled());
	}
	if (depthTest.getEnabled()) {
		if (depthTest.getDepthFunc() != _depthTest.getDepthFunc()) {
			glDepthFunc(depthTest.getDepthFunc());
			_depthTest.setDepthFunc(depthTest.getDepthFunc());
		}
		if (depthTest.getDepthMask() != _depthTest.getDepthMask()) {
			glDepthMask(depthTest.getDepthMask());
			_depthTest.setDepthMask(depthTest.getDepthMask());
		}
		if (depthTest.getNear() != _depthTest.getNear() || depthTest.getFar() != _depthTest.getFar()) {
			if (depthTest.getNear() < 0.0 || depthTest.getNear() > 1.0) {
				throw std::invalid_argument("renderState.DepthRange.Near must be between zero and one.");
			}
			if (depthTest.getFar() < 0.0 || depthTest.getFar() > 1.0) {
				throw std::invalid_argument("renderState.DepthRange.Far must be between zero and one.");
			}
			glDepthRange(depthTest.getNear(), depthTest.getFar());
			_depthTest.setNear(depthTest.getNear());
			_depthTest.setFar(depthTest.getFar());
		}
	}

	// apply Blending
	Blending blending = renderState->getBlending();
	Blending _blending = _renderState->getBlending();
	if (blending.getEnabled() != _blending.getEnabled()) {
		enable(GL_BLEND, blending.getEnabled());
		_blending.setEnabled(blending.getEnabled());
	}
	if (blending.getEnabled()) {
		if ((blending.getSrcRGB() != _blending.getSrcRGB()) ||
			(blending.getDstRGB() != _blending.getDstRGB()) ||
			(blending.getSrcAlpha() != _blending.getSrcAlpha()) ||
			(blending.getDstAlpha() != _blending.getDstAlpha())) {
			glBlendFuncSeparate(blending.getSrcRGB(), blending.getDstRGB(), blending.getSrcAlpha(), blending.getDstAlpha());
		}
		if ((blending.getRgbEquation() != _blending.getRgbEquation()) ||
			(blending.getAlphaEquation() != _blending.getAlphaEquation())) {
			glBlendEquationSeparate(blending.getRgbEquation(), blending.getAlphaEquation());
		}
	}

	// apply ColorMask
	ColorMask colorMask = renderState->getColorMask();
	ColorMask _colorMask = _renderState->getColorMask();
	if (!colorMask.equals(_colorMask)) {
		glColorMask(colorMask.getRed(), colorMask.getGreen(), colorMask.getBlue(), colorMask.getAlpha());
		_renderState->setColorMask(colorMask);
	}
};

void ContextGL3x::applyShaderProgram(DrawState* drawState, SceneState* sceneState) {
	ShaderProgram* shaderProgram = drawState->getShaderProgram();
	if (shaderProgram != _boundShaderProgram) {
		shaderProgram->use();
		_boundShaderProgram = shaderProgram;
	}
	_boundShaderProgram->clean(this, drawState, sceneState);
};