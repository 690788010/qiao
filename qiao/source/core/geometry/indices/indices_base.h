#pragma once

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class IndicesBase {
	public:
		virtual GLenum getDataType() = 0;
	};
}