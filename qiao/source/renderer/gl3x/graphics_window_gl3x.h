#pragma once

#include <string>

#include "../graphics_window.h"

#include "../../../third_party/glad/include/glad.h"
#include "../../../third_party/glfw/include/glfw3.h"


namespace qiao {
	class GraphicsWindowGL3x : public GraphicsWindow {
	public:
		GraphicsWindowGL3x(int width, int height, std::string title);
		~GraphicsWindowGL3x();
		void run();

	private:
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		void processInput(GLFWwindow* window);
		void renderLoop();

		GLFWwindow* window;
		int width;
		int height;
	};
}