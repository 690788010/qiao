/*****************************************************************//**
 * \file   shader_program.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>

#include "./shader_components/shader_vertex_attribute_collection.h"
#include "./uniforms/uniform_collection.h"
#include "./uniforms/link_auto_uniforms/link_auto_uniform_collection.h"
#include "./uniforms/link_auto_uniforms/texture_uniform.h"
#include "./uniforms/draw_auto_uniforms/model_matrix_uniform_factory.h"
#include "./uniforms/draw_auto_uniforms/draw_auto_uniform_factory_collection.h"
#include "./uniforms/draw_auto_uniforms/draw_auto_uniform_collection.h"
#include "./shader_components/shader_object.h"
#include "../scene/scene_state.h"
#include "../i_cleanable_observer.h"
#include "./uniforms/uniform_int.h"
#include "./uniforms/uniform_float.h"
#include "./uniforms/uniform_matrix_4d.h"

namespace qiao {
	class DrawState;
	class Context;

	/**
	 * ShaderProgram类用于封装着色器程序，提供对着色器的编译、链接等操作.
	 */
	class ShaderProgram : public ICleanableObserver {
	public:
		/**
		 * 构造函数.
		 * 
		 * \param vs 顶点着色器源代码
		 * \param fs 片元着色器源代码
		 */
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

		// 使用变量名查找片元着色器out变量的索引位置
		GLint getFragLocByName(std::string name);

		// 初始化AutoUniform
		void initAutoUniforms(UniformCollection uniforms);

		// 通过DrawAutoUniformCollection中保存的各个DrawAutoUniform为各个对应的Uniform自动设置值
		void setDrawAutoUniforms(Context* context, DrawState* drawState, SceneState* sceneState);

	private:
		// 为顶点着色器里的每个激活的attribute变量创建元数据
		ShaderVertexAttributeCollection _findVertexAttributes(GLuint program);

		// 为着色器里的每个激活的Uniform变量创建元数据
		UniformCollection _findUniforms(GLuint program);

		// 根据type创建对应类型的Uniform子类对象
		Uniform* _createUniform(std::string name, int location, GLenum type);

		GLuint _program;
		ShaderVertexAttributeCollection _vertexAttributes;
		std::list<ICleanable*> _dirtyUniforms;
		UniformCollection _uniforms;

		LinkAutoUniformCollection _linkAutoUniforms;
		DrawAutoUniformFactoryCollection _drawAutoUniformFactories;
		DrawAutoUniformCollection _drawAutoUniforms;
	};
}