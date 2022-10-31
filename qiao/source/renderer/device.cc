#include "device.h"
#include "./gl3x/graphics_window_gl3x.h"

using namespace qiao;

GraphicsWindow* Device::createWindow(int width, int height, std::string title, bool isFullScreen) {
	return new GraphicsWindowGL3x(width, height, title, isFullScreen);
};

