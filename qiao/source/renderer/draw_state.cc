
#include "draw_state.h"

using namespace qiao;

DrawState::DrawState() {
	_renderState = new RenderState();
}

DrawState::DrawState(RenderState* renderState) {
	_renderState = renderState;
};

DrawState::~DrawState() {
	if (_renderState != nullptr) {
		delete _renderState;
		_renderState = nullptr;
	}
}

RenderState* DrawState::getRenderState() {
	return _renderState;
};
void DrawState::setRenderState(RenderState* val) {
	_renderState = val;
};