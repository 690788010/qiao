/*****************************************************************//**
 * \file   draw_auto_uniform_factory_collection.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <map>
#include <string>
#include "draw_auto_uniform_factory.h"

namespace qiao {
	/**
	 * DrawAutoUniformCollection是std::map的子类，用于保存各个DrawAutoUniformFactory对象的指针.
	 */
	class DrawAutoUniformFactoryCollection : public std::map<std::string, DrawAutoUniformFactory*> {};
}