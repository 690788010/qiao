/**
 * @file color_mask.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief ColorMask������Ƿ�����ɫ������ɫ������д�����Ŀ�����Ϣ.
	 * @details OpenGL��glColorMask�������ڿ�����ر���ɫ���������ɫ������д������
	 * ColorMask�����ڴ��glColorMask�����Ĳ�����Ϣ��
	 */
	class ColorMask {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
		 * @details Ĭ������£�ColorMask��ָʾOpenGL������ɫ���������ɫ������д����
		 */
		ColorMask();

		/**
		 * @brief �вι��캯��
		 * @param red �Ƿ�����ɫ�����ɫ������д����
		 * @param green �Ƿ�����ɫ������ɫ������д����
		 * @param blue �Ƿ�����ɫ������ɫ������д����
		 * @param alpha �Ƿ�����ɫ����͸���ȷ�����д����
		 */
		ColorMask(bool red, bool green, bool blue, bool alpha);

		/**
		 * @brief ��ѯ�Ƿ�����ɫ�����ɫ������д����
		 * @return �Ƿ�����ɫ�����ɫ������д����
		 */
		bool getRed();

		/**
		 * @brief �����Ƿ�����ɫ�����ɫ������д����
		 * @param red �Ƿ�����ɫ�����ɫ������д����
		 * @return void
		 */
		void setRed(bool red);

		/**
		 * @brief ��ѯ�Ƿ�����ɫ������ɫ������д����
		 * @return �Ƿ�����ɫ������ɫ������д����
		 */
		bool getGreen();

		/**
		 * @brief �����Ƿ�����ɫ������ɫ������д����
		 * @param green �Ƿ�����ɫ������ɫ������д����
		 * @return void
		 */
		void setGreen(bool green);

		/**
		 * @brief ��ѯ�Ƿ�����ɫ������ɫ������д����
		 * @return �Ƿ�����ɫ������ɫ������д����
		 */
		bool getBlue();

		/**
		 * @brief �����Ƿ�����ɫ������ɫ������д����
		 * @param green �Ƿ�����ɫ������ɫ������д����
		 * @return void
		 */
		void setBlue(bool blue);

		/**
		 * @brief ��ѯ�Ƿ�����ɫ����͸���ȷ�����д����
		 * @return �Ƿ�����ɫ����͸���ȷ�����д����
		 */
		bool getAlpha();

		/**
		 * @brief �����Ƿ�����ɫ����͸���ȷ�����д����
		 * @param green �Ƿ�����ɫ����͸���ȷ�����д����
		 * @return void
		 */
		void setAlpha(bool alpha);

		/**
		 * @brief ����==�����
		 * @details ���ߵ����б�������Ⱦͷ���true�����򷵻�false
		 * @param colorMask ColorMask����
		 * @return bool
		 */
		bool operator==(ColorMask& colorMask) const;

		/**
		 * @brief ����!=�����
		 * @details ���ߵ����б�������Ⱦͷ���false�����򷵻�true
		 * @param colorMask ColorMask����
		 * @return bool
		 */
		bool operator!=(ColorMask& colorMask) const;

	private:
		bool _red;		// �Ƿ�����ɫ�����ɫ������д����
		bool _green;	// �Ƿ�����ɫ������ɫ������д����
		bool _blue;		// �Ƿ�����ɫ������ɫ������д����
		bool _alpha;	// �Ƿ�����ɫ����͸���ȷ�����д����
	};
}