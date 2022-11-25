#pragma once

#include <string>

#include "../../third_party/glad/include/glad.h"
#include "../../third_party/glfw/include/glfw3.h"

#include "context.h"


namespace qiao {
	class Window {
	public:
		Window(int width, int height, std::string title, bool isFullScreen = false);
		~Window();

		void run();
		Context* getContext();

		void (*resize)();
		void (*preRender)();
		void (*render)();
		void (*postRender)();
	private:
		// —≠ª∑‰÷»æ
		void renderLoop();

		// glfw: whenever the window size changed (by OS or user resize) this callback function executes
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
		void processInput(GLFWwindow* window);

		GLFWwindow* _gltfWindow;
		Context* _context;
		int _width;
		int _height;
	};
}