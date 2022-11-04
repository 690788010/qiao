#pragma once

#include <string>
#include "../../shaders/shader_program.h"
#include "shader_object_gl3x.h"

namespace qiao {
	class ShaderProgramGL3x : public ShaderProgram {
	public:
		ShaderProgramGL3x(std::string vs, std::string fs);
		virtual ~ShaderProgramGL3x();

		virtual void use();

	private: 
		ShaderObjectGL3x _vertexShader;
		ShaderObjectGL3x _fragmentShader;
		GLuint _program;
	};
}