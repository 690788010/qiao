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

		PrimitiveRestart& getPrimitiveRestart();
		void setPrimitiveRestart(PrimitiveRestart& val);

		CullFace& getCullFace();
		void setCullFace(CullFace& val);

		GLboolean getProgramPointSize();
		void setProgramPointSize(GLboolean val);

		GLenum getPolygonMode();
		void setPolygonMode(GLenum mode);

		ScissorTest& getScissorTest();
		void setScissorTest(ScissorTest& val);

		StencilTest& getStencilTest();
		void setStencilTest(StencilTest& val);

		DepthTest& getDepthTest();
		void setDepthTest(DepthTest& val);

		Blending& getBlending();
		void setBlending(Blending& val);

		ColorMask& getColorMask();
		void setColorMask(ColorMask val);

	private:
		PrimitiveRestart _primitiveRestart;
		CullFace _cullFace;
		GLboolean _programPointSize;
		GLenum _polygonMode;		// 多边形光栅化模式，可选值：GL_POINT, GL_LINE, GL_FILL.
		ScissorTest _scissorTest;	// 包含裁剪测试相关的状态信息
		StencilTest _stencilTest;	// 包含模板测试相关的状态信息
		DepthTest _depthTest;       // 包含深度测试相关的状态信息
		Blending _blending;			// 包含混合相关的状态信息
		ColorMask _colorMask;		// 是否开启颜色缓冲各个颜色分量的写操作
	};
}