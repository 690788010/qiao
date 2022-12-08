#pragma once

#include <stdexcept>

#include "./state/clear_state/clear_state.h"
#include "./state/draw_state/draw_state.h"
#include "scene/scene_state.h"
#include "../core/geometry/mesh.h"
#include "vertex_array/vertex_array.h"
#include "./state/render_state/render_state.h"
#include "../core/geometry/indices/indices_unsigned_short.h"
#include "../core/geometry/indices/indices_unsigned_int.h"

namespace qiao {
	class Context {
	public:
		Context();
		~Context();

		void clear(ClearState* clearState);
		void draw(DrawState* drawState, SceneState* sceneState);
		VertexArray createVertexArray(Mesh* mesh, ShaderVertexAttributeCollection shaderAttributes, GLenum usage);

	private:
		// Sync GL state with default render state.
		void syncRenderState(RenderState* renderState);

		// enable or disable server-side GL capabilities
		void enable(GLenum cap, bool enabled);

		// verify arguments
		void verifyDraw(DrawState* drawState, SceneState* sceneState);

		void applyBeforeDraw(DrawState* drawState, SceneState* sceneState);

		void applyRenderState(RenderState* renderState);

		void applyVertexArray(VertexArray* vertexArray);

		void applyShaderProgram(DrawState* drawState, SceneState* sceneState);

		Color _clearColor;
		double _clearDepth;
		int _clearStencil;
		RenderState* _renderState;
		ShaderProgram* _boundShaderProgram;
	};
}