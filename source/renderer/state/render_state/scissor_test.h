/**
 * @file scissor_test.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief ScissorTest类用于包含裁剪测试相关的状态信息
	 */
	class ScissorTest {
	public:
		/**
		 * @brief 默认构造函数
		 */
		ScissorTest();

		/**
		 * @brief 查询是否开启裁剪矩形
		 * @return  是否开启裁剪矩形
		 */
		bool getEnabled();

		/**
		 * @brief 设置是否开启裁剪矩形
		 * @param enabled 是否开启裁剪矩形
		 */
		void setEnabled(bool enabled);

		/**
		 * @brief 查询裁剪矩形框的左下角横坐标
		 * @return 裁剪矩形框的左下角横坐标
		 */
		int getX();

		/**
		 * @brief 设置裁剪矩形框的左下角横坐标
		 * @param x 裁剪矩形框的左下角横坐标
		 * @return void
		 */
		void setX(int x);

		/**
		 * @brief 查询裁剪矩形框的左下角纵坐标
		 * @return 裁剪矩形框的左下角纵坐标
		 */
		int getY();

		/**
		 * @brief 设置裁剪矩形框的左下角纵坐标
		 * @param y 裁剪矩形框的左下角纵坐标
		 * @return void
		 */
		void setY(int y);

		/**
		 * @brief 查询裁剪矩形框的宽度
		 * @return 裁剪矩形框的宽度
		 */
		int getWidth();

		/**
		 * @brief 设置裁剪矩形框的宽度
		 * @param width 裁剪矩形框的宽度
		 * @return void
		 */
		void setWidth(int width);

		/**
		 * @brief 查询裁剪矩形框的高度
		 * @return 裁剪矩形框的高度
		 */
		int getHeight();

		/**
		 * @brief 设置裁剪矩形框的高度
		 * @param height 裁剪矩形框的高度
		 * @return void
		 */
		void setHeight(int height);

	private:
		bool _enabled;		// 是否开启裁剪测试
		int _x;				// 裁剪矩形框的左下角横坐标
		int _y;				// 裁剪矩形框的左下角纵坐标
		int _width;			// 裁剪矩形框的宽度
		int _height;		// 裁剪矩形框的高度
	};
}