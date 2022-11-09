#pragma once

#include "link_auto_uniform.h"

namespace qiao {
	class TextureUniform : public LinkAutoUniform {
	public:
		TextureUniform(int textureUnit);
		// ��ȡUniform������
		virtual std::string getName();
		// ΪUniform����ֵ
		virtual void set(Uniform* uniform);

	private:
		int _textureUnit;
	};
}