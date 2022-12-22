
#include "window.h"

using namespace qiao;

Window::Window(int width, int height, std::string title, bool isFullScreen) {
	if (width <= 0) {
		throw std::invalid_argument("argument width can't be less than zero!");
	}
	if (height <= 0) {
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

	// 实例化GLFW窗口，这个窗口对象存放了所有和窗口相关的数据，而且会被GLFW的其他函数频繁地用到。
	GLFWmonitor* pMonitor = isFullScreen ? glfwGetPrimaryMonitor() : nullptr;
	_gltfWindow = glfwCreateWindow(width, height, title.c_str(), pMonitor, nullptr);
	// 创建失败则删除之前分配的所有资源，并抛出异常
	if (_gltfWindow == nullptr) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	// 通知GLFW将新创建的窗口上下文设置为当前线程的主上下文
	glfwMakeContextCurrent(_gltfWindow);

	// 绑定事件处理程序，使得当窗口调整大小的时候调用这个函数
	glfwSetFramebufferSizeCallback(_gltfWindow, framebuffer_size_callback);

	// GLAD：加载所有OpenGL函数的指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::runtime_error("Failed to initialize GLAD");
	}

	_context = new Context(); 
};

Window::~Window() {
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
	renderLoop();
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
		// 检测特定的键是否被按下
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
	// 按下ESC键就关闭GLFW。下一次while循环的条件检测将会失败，程序将会关闭。
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
