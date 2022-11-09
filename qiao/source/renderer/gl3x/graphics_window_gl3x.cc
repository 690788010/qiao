
#include <iostream>
#include <stdexcept>
#include "graphics_window_gl3x.h"

using namespace qiao;

GraphicsWindowGL3x::GraphicsWindowGL3x(int width, int height, std::string title, bool isFullScreen) {
	std::cout << "GraphicsWindowGL3x(int width, int height, std::string title, bool isFullScreen)" << std::endl;
	if (width < 0) {
		throw std::invalid_argument("argument width can't be less than zero!");
	}
	if (height < 0) {
		throw std::invalid_argument("argument height can't be less than zero!");
	}

	//resize = nullptr;

	// glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// glfw window creation
	GLFWmonitor* pMonitor = isFullScreen ? glfwGetPrimaryMonitor() : nullptr;
	_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (_window == nullptr) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::runtime_error("Failed to initialize GLAD");
	}

	_context = new ContextGL3x();
};

GraphicsWindowGL3x::~GraphicsWindowGL3x() {
	std::cout << "~GraphicsWindowGL3x()" << std::endl;
	if (_context != nullptr) {
		delete _context;
		_context = nullptr;
	}
	if (_window != nullptr) {
		glfwTerminate();
		_window = nullptr;
	}
}

void GraphicsWindowGL3x::renderLoop() {
	while (!glfwWindowShouldClose(_window)) {
		// input
		GraphicsWindowGL3x::processInput(_window);

		if (preRender != nullptr) {
			preRender();
		}
		// render
		if (render != nullptr) {
			render();
		}
		if (postRender != nullptr) {
			postRender();
		}

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
};

void GraphicsWindowGL3x::run() {
	std::cout << "run......" << std::endl;
	renderLoop();
	std::cout << "end loop...." << std::endl;
};

ContextGL3x* GraphicsWindowGL3x::getContext() {
	return _context;
};

void GraphicsWindowGL3x::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);

	/*if (resize != NULL) {
		resize();
	}*/
}

void GraphicsWindowGL3x::processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}