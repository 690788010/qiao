#pragma once

#include <string>
#include <stdexcept>

#include "../../../../third_party/glad/include/glad.h"

namespace qiao{
	class FragmentOutputs {
	public:
		FragmentOutputs(GLuint program);

		virtual int operator[](std::string index);
	private:
		GLuint _program;
	};
}