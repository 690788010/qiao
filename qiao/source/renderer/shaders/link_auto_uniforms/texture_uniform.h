#pragma once

#include "link_auto_uniform.h"

namespace qiao {
	class TextureUniform : public LinkAutoUniform {
	public:
		TextureUniform(int textureUnit);
		// 获取Uniform变量名
		virtual std::string getName();
		// 为Uniform设置值
		virtual void set(Uniform* uniform);

	private:
		int _textureUnit;
	};
}