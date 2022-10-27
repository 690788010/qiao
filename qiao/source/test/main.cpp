#include <iostream>

#include "../renderer/device.h"
#include "../renderer/gl3x/graphics_window_gl3x.h"

void render();

int main() {
	qiao::GraphicsWindowGL3x* window = (qiao::GraphicsWindowGL3x*)qiao::Device::createWindow(800, 600, "qiao");
	window->render = &render;
	//std::cout << window->render << std::endl;
	window->run();

	if (window != nullptr) {
		delete window;
		window = nullptr;
	}
}

void render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}