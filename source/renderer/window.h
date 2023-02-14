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
	 * @brief �����࣬���û��������ڵĳ���.
	 */
	class Window {
	public:
		/**
		 * @brief ���캯��
		 * @param width ���ڿ��
		 * @param height ���ڸ߶�
		 * @param title ���ڱ���
		 * @param isFullScreen �����Ƿ�ȫ��
		 */
		Window(int width, int height, std::string title, bool isFullScreen = false);
		~Window();

		/**
		 * @brief ����ѭ����Ⱦ.
		 * @return void
		 */
		void run();

		/**
		 * @brief ��ȡContext����ָ��.
		 * @return Context�����ָ��
		 */
		Context* getContext();

		void (*resize)();	///< ����ָ�룬���Ը�ֵ���ڴ��ڴ�С�仯ʱ������������ָ��ָ��ĺ���.

		void (*preRender)();	///< ����ָ�룬���Ը�ֵ����Ⱦÿһ֡ǰ������������ָ��ָ��ĺ���.

		void (*render)();	///< ����ָ�룬���Ը�ֵ��ѭ��������������ָ��ָ��ĺ���ȥ��Ⱦһ֡.

		void (*postRender)();	///< ����ָ�룬���Ը�ֵ����Ⱦÿһ֡�������������ָ��ָ��ĺ���.

	private:
		// ͨ��ѭ����ͣ�ĵ��ö�Ӧ����ȥ��Ⱦ������ͣѭ������صĴ������
		void _renderLoop();

		// glfw: whenever the window size changed (by OS or user resize) this callback function executes
		static void _framebuffer_size_callback(GLFWwindow* window, int width, int height);

		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
		void _processInput(GLFWwindow* window);

		GLFWwindow* _gltfWindow;
		Context* _context;
	};
}