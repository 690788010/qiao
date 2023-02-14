/*****************************************************************//**
 * \file   link_auto_uniform_collection.h
 * \brief  
 * 
 * \author DELL
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>
#include <map>
#include "link_auto_uniform.h"

namespace qiao {
	/**
	 * LinkAutoUniformCollection是std::map的子类，用于保存各个LinkAutoUniform对象的指针.
	 */
	class LinkAutoUniformCollection : public std::map<std::string, LinkAutoUniform*> {};
}