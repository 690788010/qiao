#pragma once

#include <string>

#include "../../../third_party/glad/include/glad.h"
#include "../../../third_party/glfw/include/glfw3.h"

#include "../graphics_window.h"
#include "context_gl3x.h"

namespace qiao {
	class GraphicsWindowGL3x : public GraphicsWindow {
	public:
		GraphicsWindowGL3x(int width, int height, std::string title, bool isFullScreen = false);
		~GraphicsWindowGL3x();

		// ∆Ù∂Ø‰÷»æ
		void run();

	private:
		// glfw: whenever the window size changed (by OS or user resize) this callback function executes
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
		void processInput(GLFWwindow* window);

		// —≠ª∑‰÷»æ
		void renderLoop();

		GLFWwindow* _window;
		ContextGL3x* _context;
		int width;
		int height;
	};
}