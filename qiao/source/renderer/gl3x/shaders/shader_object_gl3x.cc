
#include <iostream>
#include <stdexcept>
#include "shader_object_gl3x.h"

using namespace qiao;

ShaderObjectGL3x::ShaderObjectGL3x() {}

ShaderObjectGL3x::ShaderObjectGL3x(ShaderType shaderType, std::string source) {
	std::string builtinConstants = 
						"#version 330";
	builtinConstants += "\n#define og_positionVertexLocation          " + VertexLocations::POSITION;
	builtinConstants += "\n#define og_normalVertexLocation            " + VertexLocations::NORMAL;
	builtinConstants += "\n#define og_textureCoordinateVertexLocation " + VertexLocations::TEXTURECOORDINATE;
	builtinConstants += "\n#define og_colorVertexLocation             " + VertexLocations::COLOR;

	std::string builtinFunctions = "";

	const GLchar* sources[] = { builtinConstants.c_str(), builtinFunctions.c_str(), source.c_str() };
	const GLint lengths[] = { builtinConstants.length(), builtinFunctions.length(), source.length() };

	_shader = glCreateShader(shaderType);
	glShaderSource(_shader, (sizeof(sources) / sizeof(sources[0])), sources, lengths);
	glCompileShader(_shader);

	int success;
	char infoLog[512];
	glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(_shader, 512, NULL, infoLog);
		throw std::invalid_argument("Could not compile shader object. Compile Log: \n" + std::string(infoLog));
	}
};

ShaderObjectGL3x::~ShaderObjectGL3x() {
	if (_shader != 0) {
		glDeleteShader(_shader);
		_shader = 0;
		std::cout << "~ShaderObjectGL3x" << std::endl;
	}
}

GLuint ShaderObjectGL3x::handle() {
	return _shader;
};