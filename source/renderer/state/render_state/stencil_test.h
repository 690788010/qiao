/**
 * @file stencil_test.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief StencilTest类用于包含模板测试相关的状态信息
	 */
	class StencilTest {
	public:
		/**
		 * @brief 默认构造函数
		 */
		StencilTest();

		/**
		 * @brief 查询是否开启模板测试
		 * 
		 * @return 是否开启模板测试 
		 */
		bool getEnabled();

		/**
		 * @brief 设置是否开启模板测试
		 * 
		 * @param enabled 是否开启模板测试
		 * 
		 * @return void
		 */
		void setEnabled(bool enabled);

	private:
		bool _enabled;		// 是否开启模板测试
	};
}