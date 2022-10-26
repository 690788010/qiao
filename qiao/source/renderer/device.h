#pragma once

#include <string>

#include "graphics_window.h"

namespace qiao {
	class Device {
	public:
		static GraphicsWindow* createWindow(int width, int height, std::string title, bool isFullScreen = false);
	};
}