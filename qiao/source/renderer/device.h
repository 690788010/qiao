#pragma once

#include <string>
#include "graphics_window.h"
#include "./gl3x/graphics_window_gl3x.h"

namespace qiao {
	class Device {
	public:
		static GraphicsWindow* createWindow(int width, int height, std::string title, bool isFullScreen = false);
	};
}