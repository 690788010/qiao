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
	 * TextureUniform��LinkAutoUniform������࣬�����ڶ�sampler2D��Ӧ��Uniform�Զ�����ֵ.
	 */
	class TextureUniform : public LinkAutoUniform {
	public:
		/**
		 * ���캯��.
		 * 
		 * \param textureUnit ����Ԫ��ֵ
		 */
		TextureUniform(int textureUnit);

		// ��ȡUniform������
		virtual std::string getName();

		// ΪUniform����ֵ
		virtual void set(Uniform* uniform);

	private:
		int _textureUnit;
	};
}