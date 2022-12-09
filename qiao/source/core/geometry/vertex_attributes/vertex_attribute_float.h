#pragma once

#include <list>
#include "vertexattribute.h"

namespace qiao {
	class VertexAttributeFloat : public VertexAttribute {
	public:
		VertexAttributeFloat(std::string name);

		virtual std::string getName();
		virtual GLenum getType();
		
		void addData(float data);
		std::list<float> getValues();

	private:
		std::string _name;
		GLenum _type;
		std::list<float> _values;
	};
}