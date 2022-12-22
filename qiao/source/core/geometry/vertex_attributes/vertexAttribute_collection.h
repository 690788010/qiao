/*****************************************************************//**
 * \file   vertexAttribute_collection.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <list>
#include "vertexattribute.h"

namespace qiao {
	/**
	 * VertexAttributeCollection����list������࣬�������ڱ�����VertexAttribute����ָ�������.
	 */
	class VertexAttributeCollection : public std::list<VertexAttribute*> {};
}