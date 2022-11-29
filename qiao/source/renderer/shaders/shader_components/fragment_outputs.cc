
#include "fragment_outputs.h"

using namespace qiao;

FragmentOutputs::FragmentOutputs(GLuint program) {
	_program = program;
};

int FragmentOutputs::operator[](std::string name) {
	int i = glGetFragDataLocation(_program, name.c_str());

	if (i == -1) {
		throw std::invalid_argument(
			"the argument is not the name of an active user-defined varying out fragment shader variable within program!");
	}
};