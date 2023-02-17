/**
 * @file blending.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
    /**
     * @brief Blending���ڰ��������ص�״̬��Ϣ
     */
	class Blending {
	public:
        /**
         * @brief Ĭ�Ϲ��캯��
         * 
         */
		Blending();

        /**
         * @brief ��ѯ�Ƿ������
         * 
         * @return �Ƿ������
         */
        bool getEnabled();

        /**
         * @brief �����Ƿ������
         * 
         * @param enabled  �Ƿ������
         * 
         * @return void
         */
        void setEnabled(bool enabled);

        /**
         * @brief ��ѯԴ��ɫRGB�����Ļ������
         *
         * @return Դ��ɫRGB�����Ļ������
         */
        GLenum getSrcRGB();

        /**
         * @brief ����Դ��ɫRGB�����Ļ������
         *
         * @param srcRGB  Դ��ɫRGB�����Ļ������
         *
         * @return void
         */
        void setSrcRGB(GLenum srcRGB);

        /**
         * @brief ��ѯĿ����ɫRGB�����Ļ������
         *
         * @return Ŀ����ɫRGB�����Ļ������
         */
        GLenum getDstRGB();

        /**
         * @brief ����Ŀ����ɫRGB�����Ļ������
         *
         * @param dstRGB  Ŀ����ɫRGB�����Ļ������
         *
         * @return void
         */
        void setDstRGB(GLenum dstRGB);

        /**
         * @brief ��ѯԴ��ɫalpha�����Ļ������
         *
         * @return Դ��ɫalpha�����Ļ������
         */
        GLenum getSrcAlpha();

        /**
         * @brief ����Դ��ɫalpha�����Ļ������
         *
         * @param srcAlpha  Դ��ɫalpha�����Ļ������
         *
         * @return void
         */
        void setSrcAlpha(GLenum srcAlpha);

        /**
         * @brief ��ѯĿ����ɫalpha�����Ļ������
         *
         * @return Ŀ����ɫalpha�����Ļ������
         */
        GLenum getDstAlpha();

        /**
         * @brief ����Ŀ����ɫalpha�����Ļ������
         *
         * @param dstAlpha  Ŀ����ɫalpha�����Ļ������
         *
         * @return void
         */
        void setDstAlpha(GLenum dstAlpha);

        /**
         * @brief ��ѯ��ɫRGB�����Ļ�Ϸ���
         *
         * @return ��ɫRGB�����Ļ�Ϸ���
         */
        GLenum getRgbEquation();

        /**
         * @brief ������ɫRGB�����Ļ�Ϸ���
         *
         * @param rgbEquation  ��ɫRGB�����Ļ�Ϸ���
         *
         * @return void
         */
        void setRgbEquation(GLenum rgbEquation);

        /**
         * @brief ��ѯ��ɫalpha�����Ļ�Ϸ���
         *
         * @return ��ɫalpha�����Ļ�Ϸ���
         */
        GLenum getAlphaEquation();

        /**
         * @brief ������ɫalpha�����Ļ�Ϸ���
         *
         * @param alphaEquation  ��ɫalpha�����Ļ�Ϸ���
         *
         * @return void
         */
        void setAlphaEquation(GLenum alphaEquation);

	private:
		bool _enabled;                  // �Ƿ������
        // ���±����Ŀ�ѡֵ��飺https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBlendFuncSeparate.xhtml
        GLenum _srcRGB;                 // Դ��ɫRGB�����Ļ������
        GLenum _dstRGB;                 // Ŀ����ɫRGB�����Ļ������
        GLenum _srcAlpha;               // Դ��ɫalpha�����Ļ������
        GLenum _dstAlpha;               // Ŀ����ɫalpha�����Ļ������
        // ���±����Ŀ�ѡֵ��飺https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBlendEquationSeparate.xhtml
        GLenum _rgbEquation;     // ��ɫRGB�����Ļ�Ϸ���
        GLenum _alphaEquation;   // ��ɫalpha�����Ļ�Ϸ���
	};
}