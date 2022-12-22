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
	 * IndicesUnsignedShort����IndicesBase������࣬�����ڱ�ʾMesh���޷��Ŷ���������������Ϣ.
	 */
	class IndicesUnsignedShort : public IndicesBase {
	public:
		virtual GLenum getType();

		virtual size_t getSize();

		// ���һ������
		void addIndex(unsigned short index);

		unsigned short getIndex(unsigned int idx);

	private:
		std::vector<unsigned short> _values;
	};
}