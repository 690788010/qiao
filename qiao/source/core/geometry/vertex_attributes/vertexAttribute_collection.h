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
	 * VertexAttributeCollection类是list类的子类，它是用于保存多个VertexAttribute对象指针的容器.
	 */
	class VertexAttributeCollection : public std::list<VertexAttribute*> {};
}