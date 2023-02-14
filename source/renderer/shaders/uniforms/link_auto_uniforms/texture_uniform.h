/*****************************************************************//**
 * \file   texture_uniform.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "link_auto_uniform.h"

namespace qiao {
	/**
	 * TextureUniform是LinkAutoUniform类的子类，它用于对sampler2D对应的Uniform自动设置值.
	 */
	class TextureUniform : public LinkAutoUniform {
	public:
		/**
		 * 构造函数.
		 * 
		 * \param textureUnit 纹理单元的值
		 */
		TextureUniform(int textureUnit);

		// 获取Uniform变量名
		virtual std::string getName();

		// 为Uniform设置值
		virtual void set(Uniform* uniform);

	private:
		int _textureUnit;
	};
}