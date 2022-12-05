#pragma once

#include<list>
#include "indices_base.h"

namespace qiao {
	class IndicesUnsignedShort : public IndicesBase {
	public:
		virtual GLenum getType();

		void addIndex(unsigned short index);

	private:
		std::list<unsigned short> _values;
	};
}