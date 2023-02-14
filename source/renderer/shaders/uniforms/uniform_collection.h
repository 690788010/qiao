/*****************************************************************//**
 * \file   uniform_collection.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <map>
#include "uniform.h"

namespace qiao {
	/**
	 * UniformCollection类是map类的子类，它用于保存由uniform变量名和Uniform子类对象的地址构成的键值对.
	 */
	class UniformCollection : public std::map<std::string, Uniform*> { };
}