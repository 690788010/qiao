#pragma once

namespace qiao {
	class GraphicsWindow {
	public:
		void (*resize)();
		void (*preRender)();
		void (*render)();
		void (*postRender)();
		virtual void run() = 0;
	};
}