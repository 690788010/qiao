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
	 * IndicesUnsignedInt����IndicesBase������࣬�����ڱ�ʾMesh���޷�����������������Ϣ.
	 */
	class IndicesUnsignedInt : public IndicesBase {
	public:
		virtual GLenum getType();

		virtual size_t getSize();

		// ���һ������
		void addIndex(unsigned int index);

		unsigned int getIndex(unsigned int idx);

	private:
		std::vector<unsigned int> _values;
	};
}