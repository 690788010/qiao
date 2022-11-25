#pragma once

#include <string>

#include "shader_vertex_attribute_collection.h"
#include "uniform_collection.h"
#include "./link_auto_uniforms/link_auto_uniform_collection.h"
#include "./link_auto_uniforms/texture_uniform.h"
#include "draw_auto_uniforms/model_matrix_uniform_factory.h"
#include "./draw_auto_uniforms/draw_auto_uniform_factory_collection.h"
#include "./draw_auto_uniforms/draw_auto_uniform_collection.h"
#include "shader_object.h"
#include "../scene/scene_state.h"
#include "../i_cleanable_observer.h"
#include "fragment_outputs.h"

namespace qiao {
	class DrawState;
	class Context;

	class ShaderProgram : public ICleanableObserver {
	public:
		ShaderProgram(std::string vs, std::string fs);
		~ShaderProgram();

		void use();

		// 更新DrawAutoUniform对应Uniform的值，并使用
		// GL调用将_dirtyUniforms中Uniform已变化的值传送到GPU
		void clean(Context* context, DrawState* drawState, SceneState* sceneState);

		// 将实现了ICleanable接口的类对象加入_dirtyUniforms中
		virtual void notifyDirty(ICleanable* value);

		ShaderVertexAttributeCollection vertexAttributes();
		UniformCollection& uniforms();

		// 初始化AutoUniform
		void initAutoUniforms(UniformCollection uniforms);

		// 通过DrawAutoUniformCollection中保存的各个DrawAutoUniform为各个对应的Uniform自动设置值
		void setDrawAutoUniforms(Context* context, DrawState* drawState, SceneState* sceneState);

	private:
		// 为顶点着色器里的每个激活的attribute变量构建元数据
		ShaderVertexAttributeCollection findVertexAttributes(GLuint program);
		UniformCollection findUniforms(GLuint program);
		Uniform* createUniform(std::string name, int location, GLenum type);

		GLuint _program;
		FragmentOutputs* _fragmentOutputs;
		ShaderVertexAttributeCollection _vertexAttributes;
		std::list<ICleanable*> _dirtyUniforms;
		UniformCollection _uniforms;

		LinkAutoUniformCollection _linkAutoUniforms;
		DrawAutoUniformFactoryCollection _drawAutoUniformFactories;
		DrawAutoUniformCollection _drawAutoUniforms;
	};
}