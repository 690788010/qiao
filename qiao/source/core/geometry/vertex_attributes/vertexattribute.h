/*****************************************************************//**
 * \file   vertexattribute.h
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
	 * VertexAttribute���ǳ����࣬�����ڳ����ʾMesh�Ķ��㼸������.
	 */
	class VertexAttribute {
	public:
		virtual std::string getName() = 0;
		virtual GLenum getType() = 0;
	};
}