/*****************************************************************//**
 * \file   indices_unsigned_short.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include<vector>
#include "indices_base.h"

namespace qiao {
	/**
	 * IndicesUnsignedShort类是IndicesBase类的子类，它用于表示Mesh的无符号短整数顶点索引信息.
	 */
	class IndicesUnsignedShort : public IndicesBase {
	public:
		virtual GLenum getType();

		virtual size_t getSize();

		// 添加一个索引
		void addIndex(unsigned short index);

		unsigned short getIndex(unsigned int idx);

	private:
		std::vector<unsigned short> _values;
	};
}