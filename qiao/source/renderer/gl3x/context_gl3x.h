#pragma once

#include "../context.h"

namespace qiao {
	class ContextGL3x : public Context {
	public:
		ContextGL3x(int width, int height);
		~ContextGL3x();
	};
}