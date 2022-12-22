/*****************************************************************//**
 * \file   vertex_attribute_vector4f.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <list>
#include "vertexattribute.h"
#include "../../vector/vector4f.h"
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * VertexAttributeVector4F类是VertexAttribute类的子类，它用于表示Mesh类的顶点单精度浮点数向量数据..
	 */
	class VertexAttributeVector4F : public VertexAttribute {
	public:
		VertexAttributeVector4F(std::string name);
		~VertexAttributeVector4F();

		virtual std::string getName();
		virtual GLenum getType();

		// 添加一个单精度浮点数向量数据
		void addData(Vector4F* data);

		// 获取保存数据的list容器
		std::list<Vector4F*>& getValues();

	private:
		std::string _name;				// 变量名
		GLenum _type;					// 对应的OpenGL数据类型
		std::list<Vector4F*> _values;
	};
}