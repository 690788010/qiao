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
#include "./shader_components/fragment_outputs.h"
#include "./uniforms/uniform_int.h"
#include "./uniforms/uniform_float.h"
#include "./uniforms/uniform_matrix_4d.h"

namespace qiao {
	class DrawState;
	class Context;

	/**
	 * ShaderProgram�����ڷ�װ��ɫ�������ṩ����ɫ���ı��롢���ӵȲ���.
	 */
	class ShaderProgram : public ICleanableObserver {
	public:
		/**
		 * ���캯��.
		 * 
		 * \param vs ������ɫ��Դ����
		 * \param fs ƬԪ��ɫ��Դ����
		 */
		ShaderProgram(std::string vs, std::string fs);
		~ShaderProgram();

		void use();

		// ����DrawAutoUniform��ӦUniform��ֵ����ʹ��
		// GL���ý�_dirtyUniforms��Uniform�ѱ仯��ֵ���͵�GPU
		void clean(Context* context, DrawState* drawState, SceneState* sceneState);

		// ��ʵ����ICleanable�ӿڵ���������_dirtyUniforms��
		virtual void notifyDirty(ICleanable* value);

		ShaderVertexAttributeCollection vertexAttributes();
		UniformCollection& uniforms();

		// ��ʼ��AutoUniform
		void initAutoUniforms(UniformCollection uniforms);

		// ͨ��DrawAutoUniformCollection�б���ĸ���DrawAutoUniformΪ������Ӧ��Uniform�Զ�����ֵ
		void setDrawAutoUniforms(Context* context, DrawState* drawState, SceneState* sceneState);

	private:
		// Ϊ������ɫ�����ÿ�������attribute��������Ԫ����
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