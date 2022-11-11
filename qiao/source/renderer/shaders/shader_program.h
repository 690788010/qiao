#pragma once

#include "shader_vertex_attribute_collection.h"
#include "uniform_collection.h"
#include "./link_auto_uniforms/link_auto_uniform_collection.h"
#include "./link_auto_uniforms/texture_uniform.h"
#include "./draw_auto_uniforms/draw_auto_uniform_factory_collection.h"
#include "./draw_auto_uniforms/draw_auto_uniform_collection.h"
#include "../scene/scene_state.h"

namespace qiao {
	class DrawState;
	class Context;

	class ShaderProgram {
	public:
		ShaderProgram();
		virtual ~ShaderProgram();

		virtual void use() = 0;

		virtual void clean(Context* context, DrawState* drawState, SceneState* sceneState) = 0;

		virtual ShaderVertexAttributeCollection vertexAttributes() = 0;
		virtual UniformCollection& uniforms() = 0;

		// 初始化AutoUniform
		void initAutoUniforms(UniformCollection uniforms);

		// 通过DrawAutoUniformCollection中保存的各个DrawAutoUniform为各个对应的Uniform自动设置值
		void setDrawAutoUniforms(Context* context, DrawState* drawState, SceneState* sceneState);

	private:
		LinkAutoUniformCollection _linkAutoUniforms;
		DrawAutoUniformFactoryCollection _drawAutoUniformFactories;
		DrawAutoUniformCollection _drawAutoUniforms;
	};
}