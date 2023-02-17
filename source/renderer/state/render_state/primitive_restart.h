/**
 * @file primitive_restart.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief PrimitiveRestart�����ڰ���ͼԪ������ص�״̬��Ϣ
	 */
	class PrimitiveRestart {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
		 */
		PrimitiveRestart();

		/**
		 * @brief ��ѯ�Ƿ���ͼԪ����
		 * @return �Ƿ���ͼԪ����
		 */
		bool getEnabled();

		/**
		 * @brief �����Ƿ���ͼԪ����
		 * @param enabled �Ƿ���ͼԪ����
		 * @return void
		 */
		void setEnabled(bool enabled);

		/**
		 * @brief ��ȡͼԪ����������
		 * @return ͼԪ����������
		 */
		int getIndex();

		/**
		 * @brief ����ͼԪ����������
		 * @param index ͼԪ����������
		 * @return void
		 */
		void setIndex(int index);

	private:
		bool _enabled;		// �Ƿ���ͼԪ����
		int _index;			// ͼԪ����������
	};
}