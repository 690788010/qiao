#pragma once

#include <string>

namespace qiao {
	class FragmentOutputs {
		virtual int operator[](std::string name) = 0;
	};
}