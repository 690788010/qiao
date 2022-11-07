#pragma once

#include <string>
#include "../../shaders/shader_program.h"
#include "shader_object_gl3x.h"
#include "../../shaders/shader_vertex_attribute_collection.h"
#include "fragment_outputs_gl3x.h"

namespace qiao {
	class ShaderProgramGL3x : public ShaderProgram {
	public:
		ShaderProgramGL3x(std::string vs, std::string fs);
		virtual ~ShaderProgramGL3x();

		virtual void use();

		virtual ShaderVertexAttributeCollection vertexAttributes();

	private:
		// 为顶点着色器里的每个激活的attribute变量构建元数据
		static ShaderVertexAttributeCollection findVertexAttributes(GLuint program);

		GLuint _program;
		FragmentOutputsGL3x _fragmentOutputs;
		ShaderVertexAttributeCollection _vertexAttributes;
	};
}