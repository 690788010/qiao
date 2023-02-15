/**
 * @file context.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

#include "../render_state/scissor_test.h"
#include "../render_state/color_mask.h"
#include "../../third_party/glad/include/glad.h"
#include "../../../core/color/color.h"
#include "../render_state/depth_test.h"

namespace qiao {
	class ClearState {
	public:
		ClearState();

		/**
		 * @brief 获取指示清除哪个缓存的掩码
		 * 
		 * @return 指示清除哪个缓存的掩码
		 */
		GLbitfield getClearMask();

		/**
		 * @brief 设置指示清除哪个缓存的掩码
		 * 
		 * @param clearMask 指示清除哪个缓存的掩码
		 * 
		 * @return void
		 */
		void setClearMask(GLbitfield clearMask);

		/**
		 * @brief 获取颜色缓存的颜色值
		 *
		 * @return 颜色缓存的颜色值
		 */
		const Color& getColor();

		/**
		 * @brief 设置颜色缓存的颜色值
		 * 
		 * @param color 颜色缓存的颜色值
		 * 
		 * @return void
		 */
		void setColor(Color color);

		/**
		 * @brief 获取深度缓存的深度值	
		 * 
		 * @return 深度缓存的深度值
		 */
		double getDepth();

		/**
		 * @brief 设置深度缓存的深度值 
		 * 
		 * @param depth 深度缓存的深度值
		 * 
		 * @return void
		 */
		void setDepth(double depth);

		/**
		 * @brief 获取模板缓存的模板值
		 * 
		 * @return 模板缓存的模板值
		 */
		int getStencil();

		/**
		 * @brief 设置模板缓存的模板值
		 * 
		 * @param stencil 模板缓存的模板值
		 * 
		 * @return void
		 */
		void setStencil(int stencil);

		/**
		 * @brief 查询是否开启颜色缓冲各个颜色分量的写操作
		 * @return ColorMask对象的引用
		 */
		const ColorMask& getColorMask();

		/**
		 * @brief 设置是否开启颜色缓冲各个颜色分量的写操作
		 * @param colorMask 是否开启颜色缓冲各个颜色分量的写操作
		 * @return void
		 */
		void setColorMask(ColorMask colorMask);

		GLboolean getDepthMask();
		void setDepthMask(GLboolean flag);

		const ScissorTest& getScissorTest();
		void setScissorTest(ScissorTest val);

	private:
		GLbitfield _clearMask;			// 指示清除哪个缓存的掩码。可选的三个掩码值：GL_COLOR_BUFFER_BIT, 
										// GL_DEPTH_BUFFER_BIT, GL_STENCIL_BUFFER_BIT
		Color _color;					// 颜色缓存的颜色
		double _depth;					// 深度缓存的深度值		
		int _stencil;					// 模板缓存的模板值
		ColorMask _colorMask;			// 是否开启颜色缓冲各个颜色分量的写操作
		GLboolean _depthMask;			// 是否开启深度缓冲的写操作
		ScissorTest _scissorTest;		// 裁剪测试相关配置
	};
}