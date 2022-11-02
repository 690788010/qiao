#pragma once

#include <string>
#include "../../shaders/shader_program.h"


namespace qiao {
	class ShaderProgramGL3x : public ShaderProgram {
	public:
		ShaderProgramGL3x(std::string vs, std::string fs);
	};
}