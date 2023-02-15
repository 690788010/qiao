/**
 * @file color.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief ��ʾ��ɫ���ࡣʹ�ú졢�̡�����͸�������ĸ�������ʾ��ɫ��
	 */
	class Color {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
		 * 
		 */
		Color();
		/**
		 * @brief ���캯��
		 * 
		 * @param red ��ɫ��������ֵ��ΧΪ[0, 1]
		 * @param green ��ɫ��������ֵ��ΧΪ[0, 1]
		 * @param blue ��ɫ��������ֵ��ΧΪ[0, 1]
		 * @param alpha ͸���ȣ���ֵ��ΧΪ[0, 1]
		 */
		Color(double red, double green, double blue, double alpha);

		static Color WHITE;		///< ��̬Colorʵ������ɫ��ɫ��#FFFFFF
		static Color BLACK;		///< ��̬Colorʵ������ɫ��ɫ��#000000

		/**
		 * @brief ��ȡ��ɫ����
		 * 
		 * @return ��ɫ����ֵ
		 */
		double getRed() const;
		/**
		 * @brief ���ú�ɫ����
		 *
		 * @param red ��ɫ����ֵ
		 */
		void setRed(double red);

		/**
		 * @brief ��ȡ��ɫ����
		 *
		 * @return ��ɫ����ֵ
		 */
		double getGreen() const;
		/**
		 * @brief ������ɫ����
		 * 
		 * @param green ��ɫ����ֵ
		 */
		void setGreen(double green);

		/**
		 * @brief ��ȡ��ɫ����
		 *
		 * @return ��ɫ����ֵ
		 */
		double getBlue() const;
		/**
		 * @brief ������ɫ����
		 *
		 * @param blue ��ɫ����ֵ
		 */
		void setBlue(double blue);

		/**
		 * @brief ��ȡ͸���ȷ���
		 *
		 * @return ͸���ȷ���ֵ
		 */
		double getAlpha() const;
		/**
		 * @brief ����͸���ȷ���
		 *
		 * @param alpha ͸���ȷ���ֵ
		 */
		void setAlpha(double alpha);

		/**
		 * @brief ����==�����
		 * @details �졢�̡�����͸���ȷ�������ȣ��ŷ���true����һ����ɫ��������Ⱦͷ���false��
		 * @param color Color���������
		 * @return bool 
		 */
		bool operator==(Color& color) const;

		/**
		 * @brief ����!=�����
		 * @details �졢�̡�����͸���ȷ�������ȣ��ŷ���false����һ����ɫ��������Ⱦͷ���true��
		 * @param color Color���������
		 * @return bool
		 */
		bool operator!=(Color& color) const;

	private:
		double _red;	// ��ɫ��������ֵ��ΧΪ[0, 1]
		double _green;	// ��ɫ��������ֵ��ΧΪ[0, 1]
		double _blue;	// ��ɫ��������ֵ��ΧΪ[0, 1]
		double _alpha;	// ͸���ȣ���ֵ��ΧΪ[0, 1]
	};
}