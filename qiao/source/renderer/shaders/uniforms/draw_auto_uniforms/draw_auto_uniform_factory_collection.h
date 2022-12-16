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
	 * DrawAutoUniformCollection��std::map�����࣬���ڱ������DrawAutoUniformFactory�����ָ��.
	 */
	class DrawAutoUniformFactoryCollection : public std::map<std::string, DrawAutoUniformFactory*> {};
}