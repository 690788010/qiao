#include "vertex_attribute_vector4f.h"

using namespace qiao;

VertexAttributeVector4F::VertexAttributeVector4F(std::string name) {
	_name = name;
	_type = GL_FLOAT_VEC4;
};

VertexAttributeVector4F::~VertexAttributeVector4F() {
	if (!_values.empty()) {
		for (Vector4F* data : _values) {
			delete data;
			data = nullptr;
		}
	}
};

std::string VertexAttributeVector4F::getName() {
	return _name;
};

GLenum VertexAttributeVector4F::getType() {
	return _type;
};

void VertexAttributeVector4F::addData(Vector4F* data) {
	_values.push_back(data);
};