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
	 * VertexAttributeVector4F����VertexAttribute������࣬�����ڱ�ʾMesh��Ķ��㵥���ȸ�������������..
	 */
	class VertexAttributeVector4F : public VertexAttribute {
	public:
		VertexAttributeVector4F(std::string name);
		~VertexAttributeVector4F();

		virtual std::string getName();
		virtual GLenum getType();

		// ���һ�������ȸ�������������
		void addData(Vector4F* data);

		// ��ȡ�������ݵ�list����
		std::list<Vector4F*>& getValues();

	private:
		std::string _name;				// ������
		GLenum _type;					// ��Ӧ��OpenGL��������
		std::list<Vector4F*> _values;
	};
}