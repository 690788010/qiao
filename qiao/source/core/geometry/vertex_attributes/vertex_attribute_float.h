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
	 * VertexAttributeFloat����VertexAttribute������࣬�����ڱ�ʾMesh��Ķ��㵥���ȸ���������.
	 */
	class VertexAttributeFloat : public VertexAttribute {
	public:
		VertexAttributeFloat(std::string name);

		virtual std::string getName();
		virtual GLenum getType();
		
		// ���һ�������ȸ���������
		void addData(float data);

		// ��ȡ�������ݵ�list����
		std::list<float>& getValues();

	private:
		std::string _name;				// ������
		GLenum _type;					// ��Ӧ��OpenGL��������
		std::list<float> _values;
	};
}