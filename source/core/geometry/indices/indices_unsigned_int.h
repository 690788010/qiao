/*****************************************************************//**
 * \file   indices_unsigned_int.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <vector>
#include "indices_base.h"

namespace qiao {
	/**
	 * IndicesUnsignedInt类是IndicesBase类的子类，它用于表示Mesh的无符号整数顶点索引信息.
	 */
	class IndicesUnsignedInt : public IndicesBase {
	public:
		virtual GLenum getType();

		virtual size_t getSize();

		// 添加一个索引
		void addIndex(unsigned int index);

		unsigned int getIndex(unsigned int idx);

	private:
		std::vector<unsigned int> _values;
	};
}