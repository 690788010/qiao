#pragma once

#include <list>

#include "indices_base.h"

namespace qiao {
	class IndicesUnsignedInt : public IndicesBase {
	public:
		virtual GLenum getType();

		void addIndex(unsigned int index);

	private:
		std::list<unsigned int> _values;
	};
}