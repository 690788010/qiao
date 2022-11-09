#pragma once

#include <string>
#include "../uniform.h"

namespace qiao {
	class LinkAutoUniform {
	public:
		// 获取对应的Uniform变量名
		virtual std::string getName() = 0;
		// 为对应的Uniform设置值
		virtual void set(Uniform* uniform) = 0;
	};
}