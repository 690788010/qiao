/*****************************************************************//**
 * \file   shader_object.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * 着色器attribute变量的索引位置的枚举.
	 */
	enum VertexLocations {
		POSITION = 0,
		NORMAL = 2,
		TEXTURECOORDINATE = 3,
		COLOR = 4
	};

	/**
	 * 着色器类型的枚举.
	 */
	enum ShaderType {
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER
	};

	/**
	 * ShaderObject类表示着色器对象，提供编译着色器源码等功能.
	 */
	class ShaderObject {
	public:
		/**
		 * 构造函数.
		 * 
		 * \param shaderType 着色器类型
		 * \param source 着色器源码
		 */
		ShaderObject(ShaderType shaderType, std::string source);

		~ShaderObject();

		GLuint handle();

	private:
		GLuint _shader;
	};
}