#pragma once

#include <vector>

#include "indices_base.h"

namespace qiao {
	class IndicesUnsignedInt : public IndicesBase {
	public:
		virtual GLenum getType();

		virtual size_t getSize();

		void addIndex(unsigned int index);

		unsigned short getIndex(unsigned int idx);

	private:
		std::vector<unsigned int> _values;
	};
}