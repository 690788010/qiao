
#include <iostream>
#include "draw_state.h"

using namespace qiao;

DrawState::DrawState(RenderState* renderState, ShaderProgram* shaderProgram, VertexArray* vertexArray) {
	std::cout << "DrawState(RenderState* renderState, ShaderProgram* shaderProgram)" << std::endl;
	_renderState = renderState;
	_shaderProgram = shaderProgram;
	_vertexArray = vertexArray;
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
	if (_vertexArray != nullptr) {
		delete _vertexArray;
		_vertexArray = nullptr;
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

VertexArray* DrawState::getVertexArray() {
	return _vertexArray;
};

void DrawState::setVertexArray(VertexArray* vertexArray) {
	_vertexArray = vertexArray;
};