#pragma once

#include "../../shaders/fragment_outputs.h"
#include "../../../../third_party/glad/include/glad.h"

namespace qiao{
	class FragmentOutputsGL3x : public FragmentOutputs {
	public:
		FragmentOutputsGL3x() = default;
		FragmentOutputsGL3x(GLuint program);

		virtual int operator[](std::string index);
	private:
		GLuint _program;
	};
}