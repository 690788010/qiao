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
	 * DrawAutoUniformCollection����std::list������࣬�����ڱ������DrawAutoUniform�����ָ��.
	 */
	class DrawAutoUniformCollection : public std::list<DrawAutoUniform*> {};
}