/**
 * @file scissor_test.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief ScissorTest�����ڰ����ü�������ص�״̬��Ϣ
	 */
	class ScissorTest {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
		 */
		ScissorTest();

		/**
		 * @brief ��ѯ�Ƿ����ü�����
		 * @return  �Ƿ����ü�����
		 */
		bool getEnabled();

		/**
		 * @brief �����Ƿ����ü�����
		 * @param enabled �Ƿ����ü�����
		 */
		void setEnabled(bool enabled);

		/**
		 * @brief ��ѯ�ü����ο�����½Ǻ�����
		 * @return �ü����ο�����½Ǻ�����
		 */
		int getX();

		/**
		 * @brief ���òü����ο�����½Ǻ�����
		 * @param x �ü����ο�����½Ǻ�����
		 * @return void
		 */
		void setX(int x);

		/**
		 * @brief ��ѯ�ü����ο�����½�������
		 * @return �ü����ο�����½�������
		 */
		int getY();

		/**
		 * @brief ���òü����ο�����½�������
		 * @param y �ü����ο�����½�������
		 * @return void
		 */
		void setY(int y);

		/**
		 * @brief ��ѯ�ü����ο�Ŀ��
		 * @return �ü����ο�Ŀ��
		 */
		int getWidth();

		/**
		 * @brief ���òü����ο�Ŀ��
		 * @param width �ü����ο�Ŀ��
		 * @return void
		 */
		void setWidth(int width);

		/**
		 * @brief ��ѯ�ü����ο�ĸ߶�
		 * @return �ü����ο�ĸ߶�
		 */
		int getHeight();

		/**
		 * @brief ���òü����ο�ĸ߶�
		 * @param height �ü����ο�ĸ߶�
		 * @return void
		 */
		void setHeight(int height);

	private:
		bool _enabled;		// �Ƿ����ü�����
		int _x;				// �ü����ο�����½Ǻ�����
		int _y;				// �ü����ο�����½�������
		int _width;			// �ü����ο�Ŀ��
		int _height;		// �ü����ο�ĸ߶�
	};
}