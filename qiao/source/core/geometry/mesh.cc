#include "mesh.h"

using namespace qiao;

Mesh::Mesh() {
	_attributes = new VertexAttributeCollection();
};

Mesh::~Mesh() {
	if (_indices != nullptr) {
		delete _indices;
	}
	if (_attributes != nullptr) {
		for (VertexAttribute* attribute : (*_attributes)) {
			delete attribute;
			attribute = nullptr;
		}
		delete _attributes;
		_attributes = nullptr;
	}
};

IndicesBase* Mesh::getIndices() {
	return _indices;
};

void Mesh::setIndices(IndicesBase* indices) {
	_indices = indices;
};

VertexAttributeCollection* Mesh::getAttributes() {
	return _attributes;
};

GLenum Mesh::getPrimitiveType() {
	return _primitiveType;
};

void Mesh::setPrimitiveType(GLenum primitiveType) {
	_primitiveType = primitiveType;
};