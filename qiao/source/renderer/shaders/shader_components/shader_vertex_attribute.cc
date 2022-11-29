
#include "shader_vertex_attribute.h"

using namespace qiao;

ShaderVertexAttribute::ShaderVertexAttribute(std::string name, int location, GLenum type, int length) {
	_name = name;
	_location = location;
	_type = type;
	_length = length;
};

std::string ShaderVertexAttribute::getName() {
	return _name;
};

int ShaderVertexAttribute::getLocation() {
	return _location;
};

GLenum ShaderVertexAttribute::getType() {
	return _type;
};

int ShaderVertexAttribute::getLength() {
	return _length;
};