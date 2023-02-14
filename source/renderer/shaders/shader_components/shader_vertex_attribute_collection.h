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
	 * ShaderVertexAttributeCollection����map������࣬�����ڱ���attribute��������ShaderVertexAttributeָ��ļ�ֵ��.
	 */
	class ShaderVertexAttributeCollection: public std::map<std::string, ShaderVertexAttribute*> {};
}