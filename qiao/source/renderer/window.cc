
#include <iostream>
#include "window.h"

using namespace qiao;

Window::Window(int width, int height, std::string title, bool isFullScreen) {
	std::cout << "Window(int width, int height, std::string title, bool isFullScreen)" << std::endl;
	if (width < 0) {
		throw std::invalid_argument("argument width can't be less than zero!");
	}
	if (height < 0) {
		throw std::invalid_argument("argument height can't be less than zero!");
	}

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
	_gltfWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (_gltfWindow == nullptr) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	glfwMakeContextCurrent(_gltfWindow);
	glfwSetFramebufferSizeCallback(_gltfWindow, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::runtime_error("Failed to initialize GLAD");
	}

	_context = new Context();
};

Window::~Window() {
	std::cout << "~QiaoWindow" << std::endl;
	if (_context != nullptr) {
		delete _context;
		_context = nullptr;
	}
	if (_gltfWindow != nullptr) {
		glfwTerminate();
		_gltfWindow = nullptr;
	}
};

void Window::run() {
	std::cout << "run......" << std::endl;
	renderLoop();
	std::cout << "end loop...." << std::endl;
};

Context* Window::getContext() {
	return _context;
};

void Window::renderLoop() {
	while (!glfwWindowShouldClose(_gltfWindow)) {
		// input
		Window::processInput(_gltfWindow);

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
		glfwSwapBuffers(_gltfWindow);
		glfwPollEvents();
	}
};

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);

	/*if (resize != NULL) {
		resize();
	}*/
}

void Window::processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
