#pragma once

#include<list>
#include "indices_base.h"

namespace qiao {
	class IndicesUnsignedShort : public IndicesBase {
	public:
		virtual GLenum getDataType();

		void addIndex(unsigned short index);

	private:
		std::list<unsigned short> _values;
	};
}