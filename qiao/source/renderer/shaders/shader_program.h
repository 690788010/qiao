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