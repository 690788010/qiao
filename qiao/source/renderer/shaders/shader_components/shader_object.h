#pragma once

#include <string>
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	enum VertexLocations {
		POSITION = 0,
		NORMAL = 2,
		TEXTURECOORDINATE = 3,
		COLOR = 4
	};

	enum ShaderType {
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER
	};

	class ShaderObject {
	public:
		ShaderObject(ShaderType shaderType, std::string source);

		~ShaderObject();

		GLuint handle();
	private:
		GLuint _shader;
	};
}