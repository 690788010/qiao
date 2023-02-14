#include "mesh.h"

using namespace qiao;

Mesh::Mesh() {
	_primitiveType = GL_TRIANGLES;
};

Mesh::~Mesh() {
	if (_indices != nullptr) {
		delete _indices;
	}
};

IndicesBase* Mesh::getIndices() {
	return _indices;
};

void Mesh::setIndices(IndicesBase* indices) {
	_indices = indices;
};

VertexAttributeCollection& Mesh::getAttributes() {
	return _attributes;
};

GLenum Mesh::getPrimitiveType() {
	return _primitiveType;
};

void Mesh::setPrimitiveType(GLenum primitiveType) {
	_primitiveType = primitiveType;
};