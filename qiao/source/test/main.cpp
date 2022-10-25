
#include "../renderer/device.h"
#include "../renderer/gl3x/graphics_window_gl3x.h"

int main() {
	qiao::GraphicsWindowGL3x* window = (qiao::GraphicsWindowGL3x*)qiao::Device::createWindow(800, 600, "qiao");
	window->run();
}