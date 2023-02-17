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

		/**
		 * @brief ��ȡͼԪ������ص�״̬��Ϣ
		 * @return PrimitiveRestart����ͼԪ������ص�״̬��Ϣ
		 */
		PrimitiveRestart& getPrimitiveRestart();

		/**
		 * @brief ����ͼԪ������ص�״̬��Ϣ
		 * @param primitiveRestart ͼԪ������ص�״̬��Ϣ
		 * @return void
		 */
		void setPrimitiveRestart(PrimitiveRestart primitiveRestart);

		/**
		 * @brief ��ȡ���޳���ص�״̬��Ϣ
		 * @return CullFace���󣬰������޳���ص�״̬��Ϣ
		 */
		CullFace& getCullFace();

		/**
		 * @brief �������޳���ص�״̬��Ϣ
		 * @param cullFace CullFace���󣬰������޳���ص�״̬��Ϣ
		 * @return void
		 */
		void setCullFace(CullFace cullFace);

		/**
		 * @brief ��ѯ�Ƿ����ͨ����ɫ�����ñ���gl_PointSize���õ�ͼԪ��С
		 * @return �Ƿ����ͨ����ɫ�����ñ���gl_PointSize���õ�ͼԪ��С
		 */
		GLboolean getProgramPointSize();

		/**
		 * @brief �����Ƿ����ͨ����ɫ�����ñ���gl_PointSize���õ�ͼԪ��С
		 * @param cullFace �Ƿ����ͨ����ɫ�����ñ���gl_PointSize���õ�ͼԪ��С
		 * @return void
		 */
		void setProgramPointSize(GLboolean programPointSize);

		/**
		 * @brief ��ѯ����ι�դ��ģʽ
		 * @return ����ι�դ��ģʽ
		 */
		GLenum getPolygonMode();

		/**
		 * @brief ���ö���ι�դ��ģʽ
		 * @param mode ����ι�դ��ģʽ
		 * @return void
		 */
		void setPolygonMode(GLenum mode);

		/**
		 * @brief ��ѯ�ü�������ص�״̬��Ϣ
		 * @return �ü�������ص�״̬��Ϣ
		 */
		ScissorTest& getScissorTest();

		/**
		 * @brief ���òü�������ص�״̬��Ϣ
		 * @param cullFace CullFace���󣬰����ü�������ص�״̬��Ϣ
		 * @return void
		 */
		void setScissorTest(ScissorTest scissorTest);

		/**
		 * @brief ��ѯģ�������ص�״̬��Ϣ
		 * @return ģ�������ص�״̬��Ϣ
		 */
		StencilTest& getStencilTest();

		/**
		 * @brief ����ģ�������ص�״̬��Ϣ
		 * @param stencilTest StencilTest���󣬰���ģ�������ص�״̬��Ϣ
		 * @return void
		 */
		void setStencilTest(StencilTest stencilTest);

		/**
		 * @brief ��ѯ��Ȳ�����ص�״̬��Ϣ
		 * @return DepthTest������Ȳ�����ص�״̬��Ϣ
		 */
		DepthTest& getDepthTest();

		/**
		 * @brief ������Ȳ�����ص�״̬��Ϣ
		 * @param stencilTest DepthTest���󣬰�����Ȳ�����ص�״̬��Ϣ
		 * @return void
		 */
		void setDepthTest(DepthTest depthTest);

		/**
		 * @brief ��ѯ�����ص�״̬��Ϣ
		 * @return Blending���󣬰��������ص�״̬��Ϣ
		 */
		Blending& getBlending();

		/**
		 * @brief ���û����ص�״̬��Ϣ
		 * @param stencilTest Blending���󣬰��������ص�״̬��Ϣ
		 * @return void
		 */
		void setBlending(Blending blending);

		/**
		 * @brief ��ѯ�Ƿ�����ɫ���������ɫ������д����
		 * @return �Ƿ�����ɫ���������ɫ������д����
		 */
		ColorMask& getColorMask();

		/**
		 * @brief �����Ƿ�����ɫ���������ɫ������д����
		 * @param colorMask �Ƿ�����ɫ���������ɫ������д����
		 * @return void
		 */
		void setColorMask(ColorMask colorMask);

	private:
		PrimitiveRestart _primitiveRestart;		// ����ͼԪ������ص�״̬��Ϣ
		CullFace _cullFace;						// �������޳���ص�״̬��Ϣ
		GLboolean _programPointSize;			// �Ƿ����ͨ����ɫ�����ñ���gl_PointSize���õ�ͼԪ��С
		GLenum _polygonMode;					// ����ι�դ��ģʽ����ѡֵ��GL_POINT, GL_LINE, GL_FILL.
		ScissorTest _scissorTest;				// �����ü�������ص�״̬��Ϣ
		StencilTest _stencilTest;				// ����ģ�������ص�״̬��Ϣ
		DepthTest _depthTest;					// ������Ȳ�����ص�״̬��Ϣ
		Blending _blending;						// ���������ص�״̬��Ϣ
		ColorMask _colorMask;					// �Ƿ�����ɫ���������ɫ������д����
	};
}