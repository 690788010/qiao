/**
 * @file render_state.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

#include "primitive_restart.h"
#include "cull_face.h"
#include "scissor_test.h"
#include "stencil_test.h"
#include "depth_test.h"
#include "blending.h"
#include "color_mask.h"

namespace qiao {
	/**
	 * @brief RenderState类用于包含各种渲染状态。
	 * 
	 * @details DrawState类包含RenderState的状态信息一起传入Context类的draw方法，以设置渲染状态
	 */
	class RenderState {
	public:
		/**
		 * @brief 默认构造函数
		 * 
		 */
		RenderState();

		/**
		 * @brief 获取图元重启相关的状态信息
		 * @return PrimitiveRestart对象，图元重启相关的状态信息
		 */
		PrimitiveRestart& getPrimitiveRestart();

		/**
		 * @brief 设置图元重启相关的状态信息
		 * @param primitiveRestart 图元重启相关的状态信息
		 * @return void
		 */
		void setPrimitiveRestart(PrimitiveRestart primitiveRestart);

		/**
		 * @brief 获取面剔除相关的状态信息
		 * @return CullFace对象，包含面剔除相关的状态信息
		 */
		CullFace& getCullFace();

		/**
		 * @brief 设置面剔除相关的状态信息
		 * @param cullFace CullFace对象，包含面剔除相关的状态信息
		 * @return void
		 */
		void setCullFace(CullFace cullFace);

		/**
		 * @brief 查询是否可以通过着色器内置变量gl_PointSize设置点图元大小
		 * @return 是否可以通过着色器内置变量gl_PointSize设置点图元大小
		 */
		GLboolean getProgramPointSize();

		/**
		 * @brief 设置是否可以通过着色器内置变量gl_PointSize设置点图元大小
		 * @param cullFace 是否可以通过着色器内置变量gl_PointSize设置点图元大小
		 * @return void
		 */
		void setProgramPointSize(GLboolean programPointSize);

		/**
		 * @brief 查询多边形光栅化模式
		 * @return 多边形光栅化模式
		 */
		GLenum getPolygonMode();

		/**
		 * @brief 设置多边形光栅化模式
		 * @param mode 多边形光栅化模式
		 * @return void
		 */
		void setPolygonMode(GLenum mode);

		/**
		 * @brief 查询裁剪测试相关的状态信息
		 * @return 裁剪测试相关的状态信息
		 */
		ScissorTest& getScissorTest();

		/**
		 * @brief 设置裁剪测试相关的状态信息
		 * @param cullFace CullFace对象，包含裁剪测试相关的状态信息
		 * @return void
		 */
		void setScissorTest(ScissorTest scissorTest);

		/**
		 * @brief 查询模板测试相关的状态信息
		 * @return 模板测试相关的状态信息
		 */
		StencilTest& getStencilTest();

		/**
		 * @brief 设置模板测试相关的状态信息
		 * @param stencilTest StencilTest对象，包含模板测试相关的状态信息
		 * @return void
		 */
		void setStencilTest(StencilTest stencilTest);

		/**
		 * @brief 查询深度测试相关的状态信息
		 * @return DepthTest对象，深度测试相关的状态信息
		 */
		DepthTest& getDepthTest();

		/**
		 * @brief 设置深度测试相关的状态信息
		 * @param stencilTest DepthTest对象，包含深度测试相关的状态信息
		 * @return void
		 */
		void setDepthTest(DepthTest depthTest);

		/**
		 * @brief 查询混合相关的状态信息
		 * @return Blending对象，包含混合相关的状态信息
		 */
		Blending& getBlending();

		/**
		 * @brief 设置混合相关的状态信息
		 * @param stencilTest Blending对象，包含混合相关的状态信息
		 * @return void
		 */
		void setBlending(Blending blending);

		/**
		 * @brief 查询是否开启颜色缓冲各个颜色分量的写操作
		 * @return 是否开启颜色缓冲各个颜色分量的写操作
		 */
		ColorMask& getColorMask();

		/**
		 * @brief 设置是否开启颜色缓冲各个颜色分量的写操作
		 * @param colorMask 是否开启颜色缓冲各个颜色分量的写操作
		 * @return void
		 */
		void setColorMask(ColorMask colorMask);

	private:
		PrimitiveRestart _primitiveRestart;		// 包含图元重启相关的状态信息
		CullFace _cullFace;						// 包含面剔除相关的状态信息
		GLboolean _programPointSize;			// 是否可以通过着色器内置变量gl_PointSize设置点图元大小
		GLenum _polygonMode;					// 多边形光栅化模式，可选值：GL_POINT, GL_LINE, GL_FILL.
		ScissorTest _scissorTest;				// 包含裁剪测试相关的状态信息
		StencilTest _stencilTest;				// 包含模板测试相关的状态信息
		DepthTest _depthTest;					// 包含深度测试相关的状态信息
		Blending _blending;						// 包含混合相关的状态信息
		ColorMask _colorMask;					// 是否开启颜色缓冲各个颜色分量的写操作
	};
}