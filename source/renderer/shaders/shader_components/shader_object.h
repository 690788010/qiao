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
	 * ��ɫ��attribute����������λ�õ�ö��.
	 */
	enum VertexLocations {
		POSITION = 0,
		NORMAL = 2,
		TEXTURECOORDINATE = 3,
		COLOR = 4
	};

	/**
	 * ��ɫ�����͵�ö��.
	 */
	enum ShaderType {
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER
	};

	/**
	 * ShaderObject���ʾ��ɫ�������ṩ������ɫ��Դ��ȹ���.
	 */
	class ShaderObject {
	public:
		/**
		 * ���캯��.
		 * 
		 * \param shaderType ��ɫ������
		 * \param source ��ɫ��Դ��
		 */
		ShaderObject(ShaderType shaderType, std::string source);

		~ShaderObject();

		GLuint handle();

	private:
		GLuint _shader;
	};
}