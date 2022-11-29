#pragma once

#include <string>
#include "../uniform.h"
#include "draw_auto_uniform.h"

namespace qiao {
	class DrawAutoUniformFactory {
	public:
		virtual std::string getName() = 0;
		virtual DrawAutoUniform* create(Uniform* uniform) = 0;
	};
}