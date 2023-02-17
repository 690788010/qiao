/**
 * @file cull_face.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * @brief CullFace类包含面剔除相关的状态信息.
	 */
	class CullFace {
	public:
		/**
		 * @brief 默认构造函数
		 * 
		 */
		CullFace();

		/**
		 * @brief 查询是否开启面剔除
		 * @return 是否开启面剔除 
		 */
		bool getEnabled();

		/**
		 * @brief 设置是否开启面剔除
		 * @param enabled 是否开启面剔除
		 * @return void
		 */
		void setEnabled(bool enabled);
		
		/**
		 * @brief 查询剔除哪一面
		 * @return 剔除哪一面
		 */
		GLenum getCullFaceMode();

		/**
		 * @brief 设置剔除哪一面
		 * @param mode 剔除哪一面,可选值详查：https://registry.khronos.org/OpenGL-Refpages/gl4/html/glCullFace.xhtml
		 * @return void
		 */
		void setCullFaceMode(GLenum mode);

		/**
		 * @brief 查询哪一面定义为正面
		 * @return 哪一面定义为正面
		 */
		GLenum getFrontFaceMode();

		/**
		 * @brief 设置哪一面定义为正面
		 * @param mode 哪一面定义为正面，可选值详查：https://registry.khronos.org/OpenGL-Refpages/gl4/html/glFrontFace.xhtml
		 * @return void
		 */
		void setFrontFaceMode(GLenum mode);

	private:
		bool _enabled;				// 是否开启面剔除
		GLenum _cullFaceMode;		// 剔除哪一面
		GLenum _frontFaceMode;		// 定义哪一面是正面
	};
}