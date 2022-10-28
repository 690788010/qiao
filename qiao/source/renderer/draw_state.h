#pragma once

#include "./render_state/render_state.h"

namespace qiao {
	class DrawState {
	public:
		DrawState();
		DrawState(RenderState* renderState);
		~DrawState();

		RenderState* getRenderState();
		void setRenderState(RenderState* val);

	private:

		RenderState* _renderState;
	};
}