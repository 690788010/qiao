
#include <stdexcept>
#include "fragment_outputs_gl3x.h"

using namespace qiao;

FragmentOutputsGL3x::FragmentOutputsGL3x(GLuint program) {
	_program = program;
};

int FragmentOutputsGL3x::operator[](std::string name) {
	int i = glGetFragDataLocation(_program, name.c_str());

	if (i == -1) {
		throw std::invalid_argument(
			"the argument is not the name of an active user-defined varying out fragment shader variable within program!");
	}
};