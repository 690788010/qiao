
#include <iostream>
#include <stdexcept>
#include "shader_program_gl3x.h"

using namespace qiao;

ShaderProgramGL3x::ShaderProgramGL3x(std::string vs, std::string fs) : _vertexShader(ShaderType::VERTEX_SHADER, vs), 
	_fragmentShader(ShaderType::FRAGMENT_SHADER, fs) {

	_program = glCreateProgram();

	glAttachShader(_program, _vertexShader.handle());
	glAttachShader(_program, _fragmentShader.handle());
	glLinkProgram(_program);
	int success;
	char infoLog[512];
	glGetProgramiv(_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_program, 512, NULL, infoLog);
		std::cout << std::string(infoLog) << std::endl;
		throw std::invalid_argument("Could not link shader program.  Link Log:  \n" + std::string(infoLog));
	}
};

ShaderProgramGL3x::~ShaderProgramGL3x() {
	if (_program != 0) {
		glDeleteProgram(_program);
		_program = 0;
		std::cout << "~ShaderProgramGL3x" << std::endl;
	}
}

void ShaderProgramGL3x::use() {
	glUseProgram(_program);
}