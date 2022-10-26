
#include <iostream>
#include <stdexcept>

#include "graphics_window_gl3x.h"


using namespace qiao;

GraphicsWindowGL3x::GraphicsWindowGL3x(int width, int height, std::string title, bool isFullScreen) {
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
	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (window == nullptr) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::runtime_error("Failed to initialize GLAD");
	}
};

GraphicsWindowGL3x::~GraphicsWindowGL3x() {
	
}

void GraphicsWindowGL3x::renderLoop() {
	while (!glfwWindowShouldClose(window)) {
		// input
		GraphicsWindowGL3x::processInput(window);

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
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
};

void GraphicsWindowGL3x::run() {
	std::cout << "run......" << std::endl;
	renderLoop();
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