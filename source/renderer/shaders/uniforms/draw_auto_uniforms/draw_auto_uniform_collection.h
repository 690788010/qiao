/*****************************************************************//**
 * \file   draw_auto_uniform_collection.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <list>
#include "draw_auto_uniform.h"

namespace qiao {
	/**
	 * DrawAutoUniformCollection类是std::list类的子类，它用于保存各个DrawAutoUniform对象的指针.
	 */
	class DrawAutoUniformCollection : public std::list<DrawAutoUniform*> {};
}