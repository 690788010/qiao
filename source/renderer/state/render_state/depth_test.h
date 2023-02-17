/**
 * @file depth_test.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * @brief DepthTest用于包含深度测试相关的状态信息
	 */
	class DepthTest {
	public:
		DepthTest();

		/**
		 * @brief 查询是否开启深度测试
		 * 
		 * @return 是否开启深度测试
		 */
		bool getEnabled();

		/**
		 * @brief 设置是否开启深度测试
		 * 
		 * @param enabled
		 */
		void setEnabled(bool enabled);

		/**
		 * @brief 查询深度值比较函数
		 * 
		 * @return 深度值比较函数
		 */
		GLenum getDepthFunc();

		/**
		 * @brief 设置深度值比较函数
		 * 
		 * @param func 深度值比较函数，可选值详查：https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDepthFunc.xhtml
		 * 
		 * @return void
		 */
		void setDepthFunc(GLenum func);

		/**
		 * @brief 查询是否开启对深度缓冲的写操作
		 * 
		 * @return  是否开启对深度缓冲的写操作
		 */
		GLboolean getDepthMask();

		/**
		 * @brief 设置是否开启对深度缓冲的写操作
		 * 
		 * @param flag 是否开启对深度缓冲的写操作
		 * 
		 * @return void
		 */
		void setDepthMask(GLboolean flag);

		/**
		 * @brief 查询深度范围的最小值
		 * 
		 * @return 深度范围的最小值
		 */
		double getNear();

		/**
		 * @brief 设置深度范围的最小值
		 * 
		 * @param near
		 * 
		 * @return void
		 */
		void setNear(double near);

		/**
		 * @brief 设置深度范围的最大值
		 * 
		 * @return 深度范围的最大值
		 */
		double getFar();

		/**
		 * @brief 设置深度范围的最大值
		 *
		 * @param far
		 *
		 * @return void
		 */
		void setFar(double far);

	private:
		bool _enabled;				// 是否开启深度测试
		GLenum _depthFunc;			// 深度值比较函数，可选值详查：https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDepthFunc.xhtml
		GLboolean _depthMask;		// 是否开启对深度缓冲的写操作
		double _near;				// 深度范围的最小值
		double _far;				// 深度范围的最大值
	};
}