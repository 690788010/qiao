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
	 * @brief DepthTest���ڰ�����Ȳ�����ص�״̬��Ϣ
	 */
	class DepthTest {
	public:
		DepthTest();

		/**
		 * @brief ��ѯ�Ƿ�����Ȳ���
		 * 
		 * @return �Ƿ�����Ȳ���
		 */
		bool getEnabled();

		/**
		 * @brief �����Ƿ�����Ȳ���
		 * 
		 * @param enabled
		 */
		void setEnabled(bool enabled);

		/**
		 * @brief ��ѯ���ֵ�ȽϺ���
		 * 
		 * @return ���ֵ�ȽϺ���
		 */
		GLenum getDepthFunc();

		/**
		 * @brief �������ֵ�ȽϺ���
		 * 
		 * @param func ���ֵ�ȽϺ�������ѡֵ��飺https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDepthFunc.xhtml
		 * 
		 * @return void
		 */
		void setDepthFunc(GLenum func);

		/**
		 * @brief ��ѯ�Ƿ�������Ȼ����д����
		 * 
		 * @return  �Ƿ�������Ȼ����д����
		 */
		GLboolean getDepthMask();

		/**
		 * @brief �����Ƿ�������Ȼ����д����
		 * 
		 * @param flag �Ƿ�������Ȼ����д����
		 * 
		 * @return void
		 */
		void setDepthMask(GLboolean flag);

		/**
		 * @brief ��ѯ��ȷ�Χ����Сֵ
		 * 
		 * @return ��ȷ�Χ����Сֵ
		 */
		double getNear();

		/**
		 * @brief ������ȷ�Χ����Сֵ
		 * 
		 * @param near
		 * 
		 * @return void
		 */
		void setNear(double near);

		/**
		 * @brief ������ȷ�Χ�����ֵ
		 * 
		 * @return ��ȷ�Χ�����ֵ
		 */
		double getFar();

		/**
		 * @brief ������ȷ�Χ�����ֵ
		 *
		 * @param far
		 *
		 * @return void
		 */
		void setFar(double far);

	private:
		bool _enabled;				// �Ƿ�����Ȳ���
		GLenum _depthFunc;			// ���ֵ�ȽϺ�������ѡֵ��飺https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDepthFunc.xhtml
		GLboolean _depthMask;		// �Ƿ�������Ȼ����д����
		double _near;				// ��ȷ�Χ����Сֵ
		double _far;				// ��ȷ�Χ�����ֵ
	};
}