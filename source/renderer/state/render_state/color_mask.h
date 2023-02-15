/**
 * @file color_mask.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief ColorMask类包含是否开启颜色缓冲颜色分量的写操作的控制信息.
	 * @details OpenGL的glColorMask函数用于开启或关闭颜色缓冲各个颜色分量的写操作，
	 * ColorMask类用于存放glColorMask函数的参数信息。
	 */
	class ColorMask {
	public:
		/**
		 * @brief 默认构造函数
		 * @details 默认情况下，ColorMask将指示OpenGL开启颜色缓冲各个颜色分量的写操作
		 */
		ColorMask();

		/**
		 * @brief 有参构造函数
		 * @param red 是否开启颜色缓冲红色分量的写操作
		 * @param green 是否开启颜色缓冲绿色分量的写操作
		 * @param blue 是否开启颜色缓冲蓝色分量的写操作
		 * @param alpha 是否开启颜色缓冲透明度分量的写操作
		 */
		ColorMask(bool red, bool green, bool blue, bool alpha);

		/**
		 * @brief 查询是否开启颜色缓冲红色分量的写操作
		 * @return 是否开启颜色缓冲红色分量的写操作
		 */
		bool getRed();

		/**
		 * @brief 设置是否开启颜色缓冲红色分量的写操作
		 * @param red 是否开启颜色缓冲红色分量的写操作
		 * @return void
		 */
		void setRed(bool red);

		/**
		 * @brief 查询是否开启颜色缓冲绿色分量的写操作
		 * @return 是否开启颜色缓冲绿色分量的写操作
		 */
		bool getGreen();

		/**
		 * @brief 设置是否开启颜色缓冲绿色分量的写操作
		 * @param green 是否开启颜色缓冲绿色分量的写操作
		 * @return void
		 */
		void setGreen(bool green);

		/**
		 * @brief 查询是否开启颜色缓冲蓝色分量的写操作
		 * @return 是否开启颜色缓冲蓝色分量的写操作
		 */
		bool getBlue();

		/**
		 * @brief 设置是否开启颜色缓冲蓝色分量的写操作
		 * @param green 是否开启颜色缓冲蓝色分量的写操作
		 * @return void
		 */
		void setBlue(bool blue);

		/**
		 * @brief 查询是否开启颜色缓冲透明度分量的写操作
		 * @return 是否开启颜色缓冲透明度分量的写操作
		 */
		bool getAlpha();

		/**
		 * @brief 设置是否开启颜色缓冲透明度分量的写操作
		 * @param green 是否开启颜色缓冲透明度分量的写操作
		 * @return void
		 */
		void setAlpha(bool alpha);

		/**
		 * @brief 重载==运算符
		 * @details 二者的所有变量都相等就返回true，否则返回false
		 * @param colorMask ColorMask对象
		 * @return bool
		 */
		bool operator==(ColorMask& colorMask) const;

		/**
		 * @brief 重载!=运算符
		 * @details 二者的所有变量都相等就返回false，否则返回true
		 * @param colorMask ColorMask对象
		 * @return bool
		 */
		bool operator!=(ColorMask& colorMask) const;

	private:
		bool _red;		// 是否开启颜色缓冲红色分量的写操作
		bool _green;	// 是否开启颜色缓冲绿色分量的写操作
		bool _blue;		// 是否开启颜色缓冲蓝色分量的写操作
		bool _alpha;	// 是否开启颜色缓冲透明度分量的写操作
	};
}