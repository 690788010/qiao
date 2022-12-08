#pragma once

#include<vector>
#include "indices_base.h"

namespace qiao {
	class IndicesUnsignedShort : public IndicesBase {
	public:
		virtual GLenum getType();

		virtual size_t getSize();

		void addIndex(unsigned short index);

		unsigned short getIndex(unsigned int idx);

	private:
		std::vector<unsigned short> _values;
	};
}