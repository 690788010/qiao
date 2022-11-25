#include "vertex_attribute_float.h"

using namespace qiao;

VertexAttributeFloat::VertexAttributeFloat(std::string name) {
	_name = name;
	_type = GL_FLOAT;
};

std::string VertexAttributeFloat::getName() {
	return _name;
};

GLenum VertexAttributeFloat::getType() {
	return _type;
};

void VertexAttributeFloat::addData(float data) {
	_values.push_back(data);
};