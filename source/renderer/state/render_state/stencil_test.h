/**
 * @file stencil_test.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief StencilTest�����ڰ���ģ�������ص�״̬��Ϣ
	 */
	class StencilTest {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
		 */
		StencilTest();

		/**
		 * @brief ��ѯ�Ƿ���ģ�����
		 * 
		 * @return �Ƿ���ģ����� 
		 */
		bool getEnabled();

		/**
		 * @brief �����Ƿ���ģ�����
		 * 
		 * @param enabled �Ƿ���ģ�����
		 * 
		 * @return void
		 */
		void setEnabled(bool enabled);

	private:
		bool _enabled;		// �Ƿ���ģ�����
	};
}