/**
 * @file color.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief 表示颜色的类。使用红、绿、蓝、透明度这四个分量表示颜色。
	 */
	class Color {
	public:
		/**
		 * @brief 默认构造函数
		 * 
		 */
		Color();
		/**
		 * @brief 构造函数
		 * 
		 * @param red 红色分量，数值范围为[0, 1]
		 * @param green 绿色分量，数值范围为[0, 1]
		 * @param blue 蓝色分量，数值范围为[0, 1]
		 * @param alpha 透明度，数值范围为[0, 1]
		 */
		Color(double red, double green, double blue, double alpha);

		static Color WHITE;		///< 静态Color实例，白色，色号#FFFFFF
		static Color BLACK;		///< 静态Color实例，黑色，色号#000000

		/**
		 * @brief 获取红色分量
		 * 
		 * @return 红色分量值
		 */
		double getRed() const;
		/**
		 * @brief 设置红色分量
		 *
		 * @param red 红色分量值
		 */
		void setRed(double red);

		/**
		 * @brief 获取绿色分量
		 *
		 * @return 绿色分量值
		 */
		double getGreen() const;
		/**
		 * @brief 设置绿色分量
		 * 
		 * @param green 绿色分量值
		 */
		void setGreen(double green);

		/**
		 * @brief 获取蓝色分量
		 *
		 * @return 蓝色分量值
		 */
		double getBlue() const;
		/**
		 * @brief 设置蓝色分量
		 *
		 * @param blue 蓝色分量值
		 */
		void setBlue(double blue);

		/**
		 * @brief 获取透明度分量
		 *
		 * @return 透明度分量值
		 */
		double getAlpha() const;
		/**
		 * @brief 设置透明度分量
		 *
		 * @param alpha 透明度分量值
		 */
		void setAlpha(double alpha);

		/**
		 * @brief 重载==运算符
		 * @details 红、绿、蓝、透明度分量都相等，才返回true；有一个颜色分量不相等就返回false。
		 * @param color Color对象的引用
		 * @return bool 
		 */
		bool operator==(Color& color) const;

		/**
		 * @brief 重载!=运算符
		 * @details 红、绿、蓝、透明度分量都相等，才返回false；有一个颜色分量不相等就返回true。
		 * @param color Color对象的引用
		 * @return bool
		 */
		bool operator!=(Color& color) const;

	private:
		double _red;	// 红色分量，数值范围为[0, 1]
		double _green;	// 绿色分量，数值范围为[0, 1]
		double _blue;	// 蓝色分量，数值范围为[0, 1]
		double _alpha;	// 透明度，数值范围为[0, 1]
	};
}