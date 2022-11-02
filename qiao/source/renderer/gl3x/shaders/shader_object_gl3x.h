#pragma once

#include <string>

namespace qiao {
	enum ShaderType {
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER
	};

	class ShaderObjectGL3x {
	public:
		ShaderObjectGL3x(ShaderType shaderType, std::string source);
	};
}