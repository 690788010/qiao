#pragma once

#include <string>
#include "../uniform.h"

namespace qiao {
	class LinkAutoUniform {
	public:
		// ��ȡ��Ӧ��Uniform������
		virtual std::string getName() = 0;
		// Ϊ��Ӧ��Uniform����ֵ
		virtual void set(Uniform* uniform) = 0;
	};
}