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
     * @brief Blending用于包含混合相关的状态信息
     */
	class Blending {
	public:
        /**
         * @brief 默认构造函数
         * 
         */
		Blending();

        /**
         * @brief 查询是否开启混合
         * 
         * @return 是否开启混合
         */
        bool getEnabled();

        /**
         * @brief 设置是否开启混合
         * 
         * @param enabled  是否开启混合
         * 
         * @return void
         */
        void setEnabled(bool enabled);

        /**
         * @brief 查询源颜色RGB分量的混合因子
         *
         * @return 源颜色RGB分量的混合因子
         */
        GLenum getSrcRGB();

        /**
         * @brief 设置源颜色RGB分量的混合因子
         *
         * @param srcRGB  源颜色RGB分量的混合因子
         *
         * @return void
         */
        void setSrcRGB(GLenum srcRGB);

        /**
         * @brief 查询目标颜色RGB分量的混合因子
         *
         * @return 目标颜色RGB分量的混合因子
         */
        GLenum getDstRGB();

        /**
         * @brief 设置目标颜色RGB分量的混合因子
         *
         * @param dstRGB  目标颜色RGB分量的混合因子
         *
         * @return void
         */
        void setDstRGB(GLenum dstRGB);

        /**
         * @brief 查询源颜色alpha分量的混合因子
         *
         * @return 源颜色alpha分量的混合因子
         */
        GLenum getSrcAlpha();

        /**
         * @brief 设置源颜色alpha分量的混合因子
         *
         * @param srcAlpha  源颜色alpha分量的混合因子
         *
         * @return void
         */
        void setSrcAlpha(GLenum srcAlpha);

        /**
         * @brief 查询目标颜色alpha分量的混合因子
         *
         * @return 目标颜色alpha分量的混合因子
         */
        GLenum getDstAlpha();

        /**
         * @brief 设置目标颜色alpha分量的混合因子
         *
         * @param dstAlpha  目标颜色alpha分量的混合因子
         *
         * @return void
         */
        void setDstAlpha(GLenum dstAlpha);

        /**
         * @brief 查询颜色RGB分量的混合方程
         *
         * @return 颜色RGB分量的混合方程
         */
        GLenum getRgbEquation();

        /**
         * @brief 设置颜色RGB分量的混合方程
         *
         * @param rgbEquation  颜色RGB分量的混合方程
         *
         * @return void
         */
        void setRgbEquation(GLenum rgbEquation);

        /**
         * @brief 查询颜色alpha分量的混合方程
         *
         * @return 颜色alpha分量的混合方程
         */
        GLenum getAlphaEquation();

        /**
         * @brief 设置颜色alpha分量的混合方程
         *
         * @param alphaEquation  颜色alpha分量的混合方程
         *
         * @return void
         */
        void setAlphaEquation(GLenum alphaEquation);

	private:
		bool _enabled;                  // 是否开启混合
        // 以下变量的可选值详查：https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBlendFuncSeparate.xhtml
        GLenum _srcRGB;                 // 源颜色RGB分量的混合因子
        GLenum _dstRGB;                 // 目标颜色RGB分量的混合因子
        GLenum _srcAlpha;               // 源颜色alpha分量的混合因子
        GLenum _dstAlpha;               // 目标颜色alpha分量的混合因子
        // 以下变量的可选值详查：https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBlendEquationSeparate.xhtml
        GLenum _rgbEquation;     // 颜色RGB分量的混合方程
        GLenum _alphaEquation;   // 颜色alpha分量的混合方程
	};
}