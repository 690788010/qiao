#pragma once

#include "./render_state/render_state.h"
#include "shaders/shader_program.h"

namespace qiao {
	class DrawState {
	public:
		DrawState();
		DrawState(RenderState* renderState, ShaderProgram* shaderProgram);

		~DrawState();

		RenderState* getRenderState();
		void setRenderState(RenderState* renderState);

		ShaderProgram* getShaderProgram();
		void setShaderProgram(ShaderProgram* shaderProgram);

	private:
		RenderState* _renderState;
		ShaderProgram* _shaderProgram;
	};
}