/*****************************************************************//**
 * \file   shader_object.cc
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#include <stdexcept>
#include "shader_object.h"

using namespace qiao;

ShaderObject::ShaderObject(ShaderType shaderType, std::string source) {
	// ������ɫ������
	std::string builtinConstants = 
						"#version 330 core\n";
	builtinConstants += "#define og_positionVertexLocation          " + std::to_string(VertexLocations::POSITION);
	builtinConstants += "\n";
	builtinConstants += "#define og_normalVertexLocation            " + std::to_string(VertexLocations::NORMAL);
	builtinConstants += "\n";
	builtinConstants += "#define og_textureCoordinateVertexLocation " + std::to_string(VertexLocations::TEXTURECOORDINATE);
	builtinConstants += "\n";
	builtinConstants += "#define og_colorVertexLocation             " + std::to_string(VertexLocations::COLOR);
	builtinConstants += "\n";

	// ������ɫ������
	std::string builtinFunctions = "";

	const GLchar* sources[] = { builtinConstants.c_str(), builtinFunctions.c_str(), source.c_str() };
	const GLint lengths[] = { builtinConstants.length(), builtinFunctions.length(), source.length() };
	
	// ������ɫ������
	_shader = glCreateShader(shaderType);
	// ����ɫ��Դ��װ���ɫ��������
	glShaderSource(_shader, 3, sources, lengths);
	// ������ɫ��Դ��
	glCompileShader(_shader);

	// �������ʧ�����׳��쳣
	int success;
	char infoLog[512];
	glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(_shader, 512, NULL, infoLog);
		throw std::invalid_argument("Could not compile shader object. Compile Log: \n" + std::string(infoLog));
	}
};

ShaderObject::~ShaderObject() {
	if (_shader != 0) {
		glDeleteShader(_shader);
		_shader = 0;
	}
}

GLuint ShaderObject::handle() {
	return _shader;
};