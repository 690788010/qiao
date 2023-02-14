/*****************************************************************//**
 * \file   shader_vertex_attribute.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>
#include "../../../../third_party/glad/include/glad.h"

namespace qiao{
	/**
	 * ShaderVertexAttribute�����ڱ�ʾ������ɫ���м����attribute������Ԫ����.
	 */
	class ShaderVertexAttribute {
	public:
		ShaderVertexAttribute(std::string name, int location, GLenum type, int length);

		std::string getName();
		int getLocation();
		GLenum getType();
		int getLength();

	private:
		std::string _name;		// ������
		int _location;			// ��������λ��
		GLenum _type;			// ��������
		int _length;			// ����ռ���ֽ�����
	};
}