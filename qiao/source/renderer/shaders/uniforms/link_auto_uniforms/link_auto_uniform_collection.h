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
	 * LinkAutoUniformCollection��std::map�����࣬���ڱ������LinkAutoUniform�����ָ��.
	 */
	class LinkAutoUniformCollection : public std::map<std::string, LinkAutoUniform*> {};
}