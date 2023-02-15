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
		 * @brief ��ȡָʾ����ĸ����������
		 * 
		 * @return ָʾ����ĸ����������
		 */
		GLbitfield getClearMask();

		/**
		 * @brief ����ָʾ����ĸ����������
		 * 
		 * @param clearMask ָʾ����ĸ����������
		 * 
		 * @return void
		 */
		void setClearMask(GLbitfield clearMask);

		/**
		 * @brief ��ȡ��ɫ�������ɫֵ
		 *
		 * @return ��ɫ�������ɫֵ
		 */
		const Color& getColor();

		/**
		 * @brief ������ɫ�������ɫֵ
		 * 
		 * @param color ��ɫ�������ɫֵ
		 * 
		 * @return void
		 */
		void setColor(Color color);

		/**
		 * @brief ��ȡ��Ȼ�������ֵ	
		 * 
		 * @return ��Ȼ�������ֵ
		 */
		double getDepth();

		/**
		 * @brief ������Ȼ�������ֵ 
		 * 
		 * @param depth ��Ȼ�������ֵ
		 * 
		 * @return void
		 */
		void setDepth(double depth);

		/**
		 * @brief ��ȡģ�建���ģ��ֵ
		 * 
		 * @return ģ�建���ģ��ֵ
		 */
		int getStencil();

		/**
		 * @brief ����ģ�建���ģ��ֵ
		 * 
		 * @param stencil ģ�建���ģ��ֵ
		 * 
		 * @return void
		 */
		void setStencil(int stencil);

		/**
		 * @brief ��ѯ�Ƿ�����ɫ���������ɫ������д����
		 * @return ColorMask���������
		 */
		const ColorMask& getColorMask();

		/**
		 * @brief �����Ƿ�����ɫ���������ɫ������д����
		 * @param colorMask �Ƿ�����ɫ���������ɫ������д����
		 * @return void
		 */
		void setColorMask(ColorMask colorMask);

		GLboolean getDepthMask();
		void setDepthMask(GLboolean flag);

		const ScissorTest& getScissorTest();
		void setScissorTest(ScissorTest val);

	private:
		GLbitfield _clearMask;			// ָʾ����ĸ���������롣��ѡ����������ֵ��GL_COLOR_BUFFER_BIT, 
										// GL_DEPTH_BUFFER_BIT, GL_STENCIL_BUFFER_BIT
		Color _color;					// ��ɫ�������ɫ
		double _depth;					// ��Ȼ�������ֵ		
		int _stencil;					// ģ�建���ģ��ֵ
		ColorMask _colorMask;			// �Ƿ�����ɫ���������ɫ������д����
		GLboolean _depthMask;			// �Ƿ�����Ȼ����д����
		ScissorTest _scissorTest;		// �ü������������
	};
}