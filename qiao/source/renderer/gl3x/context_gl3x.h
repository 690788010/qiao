#pragma once

#include "../../../third_party/glad/include/glad.h"

#include "../context.h"
#include "../render_state/render_state.h"

namespace qiao {
	class ContextGL3x : public Context {
	public:
		ContextGL3x();
		~ContextGL3x();

	private:
		// Sync GL state with default render state.
		void syncRenderState(RenderState* renderState);

		// enable or disable server-side GL capabilities
		void enable(GLenum cap, bool enabled);

		RenderState* _renderState;
	};
}