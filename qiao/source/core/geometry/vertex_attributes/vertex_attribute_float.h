/*****************************************************************//**
 * \file   vertex_attribute_float.h
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
	 * VertexAttributeFloat类是VertexAttribute类的子类，它用于表示Mesh类的顶点单精度浮点数数据.
	 */
	class VertexAttributeFloat : public VertexAttribute {
	public:
		VertexAttributeFloat(std::string name);

		virtual std::string getName();
		virtual GLenum getType();
		
		// 添加一个单精度浮点数数据
		void addData(float data);

		// 获取保存数据的list容器
		std::list<float>& getValues();

	private:
		std::string _name;				// 变量名
		GLenum _type;					// 对应的OpenGL数据类型
		std::list<float> _values;
	};
}