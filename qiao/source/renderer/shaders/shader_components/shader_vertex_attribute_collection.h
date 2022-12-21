/*****************************************************************//**
 * \file   shader_vertex_attribute_collection.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <map>
#include "shader_vertex_attribute.h"

namespace qiao {
	/**
	 * ShaderVertexAttributeCollection类是map类的子类，它用于保存attribute变量名和ShaderVertexAttribute指针的键值对.
	 */
	class ShaderVertexAttributeCollection: public std::map<std::string, ShaderVertexAttribute*> {};
}