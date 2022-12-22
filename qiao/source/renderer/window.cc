
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

	// ʵ����GLFW���ڣ�������ڶ����������кʹ�����ص����ݣ����һᱻGLFW����������Ƶ�����õ���
	GLFWmonitor* pMonitor = isFullScreen ? glfwGetPrimaryMonitor() : nullptr;
	_gltfWindow = glfwCreateWindow(width, height, title.c_str(), pMonitor, nullptr);
	// ����ʧ����ɾ��֮ǰ�����������Դ�����׳��쳣
	if (_gltfWindow == nullptr) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	// ֪ͨGLFW���´����Ĵ�������������Ϊ��ǰ�̵߳���������
	glfwMakeContextCurrent(_gltfWindow);

	// ���¼��������ʹ�õ����ڵ�����С��ʱ������������
	glfwSetFramebufferSizeCallback(_gltfWindow, framebuffer_size_callback);

	// GLAD����������OpenGL������ָ��
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
		// ����ض��ļ��Ƿ񱻰���
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
	// ����ESC���͹ر�GLFW����һ��whileѭ����������⽫��ʧ�ܣ����򽫻�رա�
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
