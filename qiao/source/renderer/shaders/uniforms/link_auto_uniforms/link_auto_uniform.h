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
	 * LinkAutoUniform����Ϊ�ض���Uniform�Զ�����ֵ.
	 */
	class LinkAutoUniform {
	public:
		// ��ȡ��Ӧ��Uniform������
		virtual std::string getName() = 0;

		// Ϊ��Ӧ��Uniform����ֵ
		virtual void set(Uniform* uniform) = 0;
	};
}