#pragma once

#include "shader_vertex_attribute_collection.h"
#include "uniform_collection.h"
#include "./link_auto_uniforms/link_auto_uniform_collection.h"
#include "./link_auto_uniforms/texture_uniform.h"
#include "./draw_auto_uniforms/draw_auto_uniform_factory_collection.h"
#include "./draw_auto_uniforms/draw_auto_uniform_collection.h"

namespace qiao {
	class DrawState;
	class Context;

	class ShaderProgram {
	public:
		ShaderProgram();
		virtual ~ShaderProgram();

		virtual void use() = 0;
		virtual void clean(Context* context, DrawState* drawState) = 0;
		virtual ShaderVertexAttributeCollection vertexAttributes() = 0;
		virtual UniformCollection& uniforms() = 0;

		// ≥ı ºªØAutoUniform
		void initAutoUniforms(UniformCollection uniforms);

	private:
		LinkAutoUniformCollection _linkAutoUniforms;
		DrawAutoUniformFactoryCollection _drawAutoUniformFactories;
		DrawAutoUniformCollection _drawAutoUniforms;
	};
}