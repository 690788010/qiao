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
	 * @brief RenderState�����ڰ���������Ⱦ״̬��
	 * 
	 * @details DrawState�����RenderState��״̬��Ϣһ����Context���draw��������������Ⱦ״̬
	 */
	class RenderState {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
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
		GLenum _polygonMode;		// ����ι�դ��ģʽ����ѡֵ��GL_POINT, GL_LINE, GL_FILL.
		ScissorTest _scissorTest;	// �����ü�������ص�״̬��Ϣ
		StencilTest _stencilTest;	// ����ģ�������ص�״̬��Ϣ
		DepthTest _depthTest;       // ������Ȳ�����ص�״̬��Ϣ
		Blending _blending;			// ���������ص�״̬��Ϣ
		ColorMask _colorMask;		// �Ƿ�����ɫ���������ɫ������д����
	};
}