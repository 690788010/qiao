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
	 * VertexAttribute类是抽象类，它用于抽象表示Mesh的顶点几何数据.
	 */
	class VertexAttribute {
	public:
		virtual std::string getName() = 0;
		virtual GLenum getType() = 0;
	};
}