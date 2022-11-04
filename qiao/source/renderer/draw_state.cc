
#include <iostream>
#include "draw_state.h"

using namespace qiao;

DrawState::DrawState() {
	std::cout << "DrawState()" << std::endl;
	_renderState = new RenderState();
}

DrawState::DrawState(RenderState* renderState, ShaderProgram* shaderProgram) {
	std::cout << "DrawState(RenderState* renderState, ShaderProgram* shaderProgram)" << std::endl;
	_renderState = renderState;
	_shaderProgram = shaderProgram;
};

DrawState::~DrawState() {
	std::cout << "~DrawState" << std::endl;
	if (_renderState != nullptr) {
		delete _renderState;
		_renderState = nullptr;
	}
	if (_shaderProgram != nullptr) {
		delete _shaderProgram;
		_shaderProgram = nullptr;
	}
}

RenderState* DrawState::getRenderState() {
	return _renderState;
};

void DrawState::setRenderState(RenderState* renderState) {
	_renderState = renderState;
};

ShaderProgram* DrawState::getShaderProgram() {
	return _shaderProgram;
};

void DrawState::setShaderProgram(ShaderProgram* shaderProgram) {
	_shaderProgram = shaderProgram;
};