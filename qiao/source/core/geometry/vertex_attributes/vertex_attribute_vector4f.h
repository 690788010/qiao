#pragma once

#include <list>
#include "vertexattribute.h"
#include "../../vector/vector4f.h"
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class VertexAttributeVector4F : public VertexAttribute {
	public:
		VertexAttributeVector4F(std::string name);
		~VertexAttributeVector4F();

		virtual std::string getName();
		virtual GLenum getType();

		void addData(Vector4F* data);
		std::list<Vector4F*> getValues();

	private:
		std::string _name;
		GLenum _type;
		std::list<Vector4F*> _values;
	};
}