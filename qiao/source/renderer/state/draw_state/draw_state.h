#pragma once

#include "../render_state/render_state.h"
#include "../../shaders/shader_program.h"
#include "../../vertex_array/vertex_array.h"

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

		VertexArray* getVertexArray();
		void setVertexArray(VertexArray* vertexArray);

	private:
		RenderState* _renderState;
		ShaderProgram* _shaderProgram;
		VertexArray* _vertexArray;
	};
}