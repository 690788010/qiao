#include "vertex_buffer_attributes_gl3x.h"

#include "../../../../third_party/glad/include/glad.h"

using namespace qiao;


VertexBufferAttributesGL3x::VertexBufferAttributesGL3x() {
	int numOfMaxVertexAttribs;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numOfMaxVertexAttribs);
	_attributes = new VertexBufferAttributeGL3x*[numOfMaxVertexAttribs];
}

VertexBufferAttributesGL3x::~VertexBufferAttributesGL3x() {
	if (_attributes != nullptr) {
		int len = sizeof(_attributes) / sizeof(_attributes[0]);
		for (int i = 0; i < len; i++) {
			delete _attributes[i];
		}
		delete _attributes;
		_attributes = nullptr;
	}
};