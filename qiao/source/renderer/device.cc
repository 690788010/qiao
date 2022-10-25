#include "device.h"
#include "./gl3x/graphics_window_gl3x.h"

using namespace qiao;

GraphicsWindow* Device::createWindow(int width, int height, std::string title) {
	GraphicsWindowGL3x window(width, height, title);
	return &window;
};

