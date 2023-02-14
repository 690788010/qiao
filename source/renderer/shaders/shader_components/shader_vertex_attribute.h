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
	 * ShaderVertexAttribute类用于表示顶点着色器中激活的attribute变量的元数据.
	 */
	class ShaderVertexAttribute {
	public:
		ShaderVertexAttribute(std::string name, int location, GLenum type, int length);

		std::string getName();
		int getLocation();
		GLenum getType();
		int getLength();

	private:
		std::string _name;		// 变量名
		int _location;			// 变量索引位置
		GLenum _type;			// 变量类型
		int _length;			// 变量占用字节数量
	};
}