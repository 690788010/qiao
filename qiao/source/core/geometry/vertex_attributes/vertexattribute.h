#pragma once

#include <string>

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class VertexAttribute {
	public:
		virtual std::string getName() = 0;
		virtual GLenum getType() = 0;
	};
}