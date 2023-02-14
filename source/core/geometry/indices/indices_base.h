/*****************************************************************//**
 * \file   indices_base.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * IndicesBase是一个抽象类，它用于表示Mesh的顶点索引信息.
	 */
	class IndicesBase {
	public:
		virtual GLenum getType() = 0;
		virtual size_t getSize() = 0;
	};
}