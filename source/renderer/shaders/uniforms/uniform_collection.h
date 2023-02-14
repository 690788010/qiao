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
	 * UniformCollection����map������࣬�����ڱ�����uniform��������Uniform�������ĵ�ַ���ɵļ�ֵ��.
	 */
	class UniformCollection : public std::map<std::string, Uniform*> { };
}