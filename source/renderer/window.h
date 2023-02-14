/**
 * @file window.h
 * @brief 
 * @author yangqiao
 * @date December 2022
 */

#pragma once

#include <string>

#include "../../third_party/glad/include/glad.h"
#include "../../third_party/glfw/include/glfw3.h"

#include "context.h"

namespace qiao {
	/**
	 * @brief 窗口类，和用户交互窗口的抽象.
	 */
	class Window {
	public:
		/**
		 * @brief 构造函数
		 * @param width 窗口宽度
		 * @param height 窗口高度
		 * @param title 窗口标题
		 * @param isFullScreen 窗口是否全屏
		 */
		Window(int width, int height, std::string title, bool isFullScreen = false);
		~Window();

		/**
		 * @brief 启动循环渲染.
		 * @return void
		 */
		void run();

		/**
		 * @brief 获取Context对象指针.
		 * @return Context对象的指针
		 */
		Context* getContext();

		void (*resize)();	///< 函数指针，可以赋值，在窗口大小变化时会调用这个函数指针指向的函数.

		void (*preRender)();	///< 函数指针，可以赋值，渲染每一帧前会调用这个函数指针指向的函数.

		void (*render)();	///< 函数指针，可以赋值，循环会调用这个函数指针指向的函数去渲染一帧.

		void (*postRender)();	///< 函数指针，可以赋值，渲染每一帧后会调用这个函数指针指向的函数.

	private:
		// 通过循环不停的调用对应函数去渲染，并不停循环做相关的处理操作
		void _renderLoop();

		// glfw: whenever the window size changed (by OS or user resize) this callback function executes
		static void _framebuffer_size_callback(GLFWwindow* window, int width, int height);

		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
		void _processInput(GLFWwindow* window);

		GLFWwindow* _gltfWindow;
		Context* _context;
	};
}