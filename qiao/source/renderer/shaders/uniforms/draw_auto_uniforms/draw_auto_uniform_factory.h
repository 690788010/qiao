/*****************************************************************//**
 * \file   draw_auto_uniform_factory.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>
#include "../uniform.h"
#include "draw_auto_uniform.h"

namespace qiao {
	/**
	 * DrawAutoUniformFactory�������ڴ�����Ӧ��DrawAutoUniform����Ĺ����࣬
	 * DrawAutoUniformFactory����һ�������࣬����ֱ��ʵ����.
	 */
	class DrawAutoUniformFactory {
	public:
		/**
		 * ���麯�������ڷ��ض�Ӧ��name.
		 * 
		 * \return std::string
		 */
		virtual std::string getName() = 0;

		/**
		 * ���麯�������ڴ�����Ӧ��DrawAutoUniform.
		 * 
		 * \param Uniform
		 * \return DrawAutoUniform*
		 */
		virtual DrawAutoUniform* create(Uniform* uniform) = 0;
	};
}