#pragma once

#include <vector>
#include "uniform.h"

namespace qiao {
	class UniformCollection : public std::vector<UniformBase*> { };
}