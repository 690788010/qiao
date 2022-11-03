#pragma once

#include "../../../third_party/glad/include/glad.h"

#include "../context.h"
#include "../render_state/render_state.h"
#include "../draw_state.h"
#include "../clear_state.h"

namespace qiao {
	class ContextGL3x : public Context {
	public:
		ContextGL3x();
		~ContextGL3x();

		virtual void clear(ClearState* clearState);

		virtual void draw(DrawState* drawState);

	private:
		// Sync GL state with default render state.
		void syncRenderState(RenderState* renderState);

		// enable or disable server-side GL capabilities
		void enable(GLenum cap, bool enabled);

		// verify arguments
		void verifyDraw(DrawState* drawState);

		void applyBeforeDraw(DrawState* drawState);

		void applyRenderState(RenderState* renderState);

		void applyShaderProgram(DrawState* drawState);

		Color _clearColor;
		double _clearDepth;
		int _clearStencil;
		RenderState* _renderState;
		ShaderProgram* _boundShaderProgram;
	};
}