#pragma once

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class IndicesBase {
	public:
		virtual GLenum getType() = 0;
		virtual size_t getSize() = 0;
	};
}