/*****************************************************************//**
 * \file   link_auto_uniform.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>
#include "../uniform.h"

namespace qiao {
	/**
	 * LinkAutoUniform用于为特定的Uniform自动设置值.
	 */
	class LinkAutoUniform {
	public:
		// 获取对应的Uniform变量名
		virtual std::string getName() = 0;

		// 为对应的Uniform设置值
		virtual void set(Uniform* uniform) = 0;
	};
}