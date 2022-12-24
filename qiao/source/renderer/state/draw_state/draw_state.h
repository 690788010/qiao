/*****************************************************************//**
 * \file   draw_state.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "../render_state/render_state.h"
#include "../../shaders/shader_program.h"
#include "../../vertex_array/vertex_array.h"

namespace qiao {
	/**
	 * DrawState类表示当前绘制的状态.
	 */
	class DrawState {
	public:
		DrawState(RenderState* renderState, ShaderProgram* shaderProgram, VertexArray* vertexArray);

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