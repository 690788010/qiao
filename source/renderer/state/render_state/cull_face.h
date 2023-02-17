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
	 * @brief CullFace��������޳���ص�״̬��Ϣ.
	 */
	class CullFace {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
		 * 
		 */
		CullFace();

		/**
		 * @brief ��ѯ�Ƿ������޳�
		 * @return �Ƿ������޳� 
		 */
		bool getEnabled();

		/**
		 * @brief �����Ƿ������޳�
		 * @param enabled �Ƿ������޳�
		 * @return void
		 */
		void setEnabled(bool enabled);
		
		/**
		 * @brief ��ѯ�޳���һ��
		 * @return �޳���һ��
		 */
		GLenum getCullFaceMode();

		/**
		 * @brief �����޳���һ��
		 * @param mode �޳���һ��,��ѡֵ��飺https://registry.khronos.org/OpenGL-Refpages/gl4/html/glCullFace.xhtml
		 * @return void
		 */
		void setCullFaceMode(GLenum mode);

		/**
		 * @brief ��ѯ��һ�涨��Ϊ����
		 * @return ��һ�涨��Ϊ����
		 */
		GLenum getFrontFaceMode();

		/**
		 * @brief ������һ�涨��Ϊ����
		 * @param mode ��һ�涨��Ϊ���棬��ѡֵ��飺https://registry.khronos.org/OpenGL-Refpages/gl4/html/glFrontFace.xhtml
		 * @return void
		 */
		void setFrontFaceMode(GLenum mode);

	private:
		bool _enabled;				// �Ƿ������޳�
		GLenum _cullFaceMode;		// �޳���һ��
		GLenum _frontFaceMode;		// ������һ��������
	};
}