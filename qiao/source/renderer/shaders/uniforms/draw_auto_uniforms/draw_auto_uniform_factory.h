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
	 * DrawAutoUniformFactory类是用于创建对应的DrawAutoUniform对象的工厂类，
	 * DrawAutoUniformFactory类是一个抽象类，不可直接实例化.
	 */
	class DrawAutoUniformFactory {
	public:
		/**
		 * 纯虚函数，用于返回对应的name.
		 * 
		 * \return std::string
		 */
		virtual std::string getName() = 0;

		/**
		 * 纯虚函数，用于创建对应的DrawAutoUniform.
		 * 
		 * \param Uniform
		 * \return DrawAutoUniform*
		 */
		virtual DrawAutoUniform* create(Uniform* uniform) = 0;
	};
}