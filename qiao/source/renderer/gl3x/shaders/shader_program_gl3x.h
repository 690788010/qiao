#pragma once

#include <string>
#include <list>
#include "../../shaders/shader_program.h"
#include "shader_object_gl3x.h"
#include "../../shaders/shader_vertex_attribute_collection.h"
#include "fragment_outputs_gl3x.h"
#include "../i_cleanable_observer.h"

namespace qiao {
	class ShaderProgramGL3x : public ShaderProgram, public ICleanableObserver {
	public:
		ShaderProgramGL3x(std::string vs, std::string fs);
		virtual ~ShaderProgramGL3x();

		virtual void use();

		//virtual void clean(Context* context, DrawState* drawState);

		virtual ShaderVertexAttributeCollection vertexAttributes();

		virtual UniformCollection uniforms();

		// 将实现了ICleanable接口的类对象加入_dirtyUniforms中
		virtual void notifyDirty(ICleanable* value);

	private:
		// 为顶点着色器里的每个激活的attribute变量构建元数据
		ShaderVertexAttributeCollection findVertexAttributes(GLuint program);
		UniformCollection findUniforms(GLuint program);
		UniformBase* createUniform(std::string name, int location, GLenum type);

		GLuint _program;
		FragmentOutputsGL3x _fragmentOutputs;
		ShaderVertexAttributeCollection _vertexAttributes;
		std::list<ICleanable*> _dirtyUniforms;
		UniformCollection _uniforms;
	};
}