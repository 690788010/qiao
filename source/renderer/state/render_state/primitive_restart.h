/**
 * @file primitive_restart.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

namespace qiao {
	/**
	 * @brief PrimitiveRestart类用于包含图元重启相关的状态信息
	 */
	class PrimitiveRestart {
	public:
		/**
		 * @brief 默认构造函数
		 */
		PrimitiveRestart();

		/**
		 * @brief 查询是否开启图元重启
		 * @return 是否开启图元重启
		 */
		bool getEnabled();

		/**
		 * @brief 设置是否开启图元重启
		 * @param enabled 是否开启图元重启
		 * @return void
		 */
		void setEnabled(bool enabled);

		/**
		 * @brief 获取图元重启的索引
		 * @return 图元重启的索引
		 */
		int getIndex();

		/**
		 * @brief 设置图元重启的索引
		 * @param index 图元重启的索引
		 * @return void
		 */
		void setIndex(int index);

	private:
		bool _enabled;		// 是否开启图元重启
		int _index;			// 图元重启的索引
	};
}