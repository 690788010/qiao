#pragma once

#include <map>
#include "uniform.h"

namespace qiao {
	class UniformCollection : public std::map<std::string, Uniform*> { };
}