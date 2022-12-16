/*****************************************************************//**
 * \file   window.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>

#include "../../third_party/glad/include/glad.h"
#include "../../third_party/glfw/include/glfw3.h"

#include "context.h"

namespace qiao {
	class Window {
	public:
		/**
		 * .
		 * ���캯��
		 * \param width ���ڳ���
		 * \param height ���ڸ߶�
		 * \param title ���ڱ���
		 * \param isFullScreen �����Ƿ�ȫ��
		 */
		Window(int width, int height, std::string title, bool isFullScreen = false);
		~Window();

		/**
		 * ����ѭ����Ⱦ.
		 */
		void run();

		/**
		 * ��ȡContext����ָ��.
		 * 
		 * \return Context*
		 */
		Context* getContext();

		/**
		 * ����ָ�룬���Ը�ֵ���ڴ��ڴ�С�仯ʱ������������ָ��ָ��ĺ���.
		 */
		void (*resize)();

		/**
		 * ����ָ�룬���Ը�ֵ����Ⱦÿһ֡ǰ������������ָ��ָ��ĺ���.
		 */
		void (*preRender)();

		/**
		 * ����ָ�룬���Ը�ֵ��ѭ��������������ָ��ָ��ĺ���ȥ��Ⱦһ֡.
		 */
		void (*render)();

		/**
		 * ����ָ�룬���Ը�ֵ����Ⱦÿһ֡�������������ָ��ָ��ĺ���.
		 */
		void (*postRender)();

	private:
		// ͨ��ѭ����ͣ�ĵ��ö�Ӧ����ȥ��Ⱦ������ͣѭ������صĴ������
		void renderLoop();

		// glfw: whenever the window size changed (by OS or user resize) this callback function executes
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
		void processInput(GLFWwindow* window);

		GLFWwindow* _gltfWindow;
		Context* _context;
	};
}