#pragma once

#include "context.h"

namespace qiao {
	class GraphicsWindow {
	public:
		void (*resize)();
		void (*preRender)();
		void (*render)();
		void (*postRender)();
		virtual void run() = 0;
		virtual Context* getContext() = 0;
	};
}