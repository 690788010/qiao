/*****************************************************************//**
 * \file   mesh.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "indices/indices_base.h"
#include "vertex_attributes/vertexattribute.h"
#include "vertex_attributes/vertexAttribute_collection.h"

namespace qiao {
	/**
	 * Mesh�����ڱ�ʾ�������ݽṹ.
	 */
	class Mesh {
	public:
		Mesh();
		~Mesh();

		IndicesBase* getIndices();
		void setIndices(IndicesBase* indices);

		VertexAttributeCollection& getAttributes();

		GLenum getPrimitiveType();
		void setPrimitiveType(GLenum primitiveType);

	private:
		IndicesBase* _indices;
		VertexAttributeCollection _attributes;
		GLenum _primitiveType;					// OpenGLͼԪ����
	};
}