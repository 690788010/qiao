
#include <iostream>
#include <stdexcept>
#include "shader_object_gl3x.h"

using namespace qiao;

ShaderObjectGL3x::ShaderObjectGL3x() {}

ShaderObjectGL3x::ShaderObjectGL3x(ShaderType shaderType, std::string source) {
	std::cout << "ShaderObjectGL3x" << std::endl;
	std::string builtinConstants = 
						"#version 330 core\n";
	builtinConstants += "#define og_positionVertexLocation          " + std::to_string(VertexLocations::POSITION);
	builtinConstants += ";\n";
	builtinConstants += "#define og_normalVertexLocation            " + std::to_string(VertexLocations::NORMAL);
	builtinConstants += ";\n";
	builtinConstants += "#define og_textureCoordinateVertexLocation " + std::to_string(VertexLocations::TEXTURECOORDINATE);
	builtinConstants += ";\n";
	builtinConstants += "#define og_colorVertexLocation             " + std::to_string(VertexLocations::COLOR);
	builtinConstants += ";\n";

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
		std::cout << std::string(infoLog) << std::endl;
		throw std::invalid_argument("Could not compile shader object. Compile Log: \n" + std::string(infoLog));
	}
};

ShaderObjectGL3x::~ShaderObjectGL3x() {
	std::cout <<"~ShaderObjectGL3x" << std::endl;
	if (_shader != 0) {
		glDeleteShader(_shader);
		_shader = 0;
		std::cout << "glDeleteShader(_shader)" << std::endl;
	}
}

GLuint ShaderObjectGL3x::handle() {
	return _shader;
};