#pragma once

#include <map>
#include "shader_vertex_attribute.h"

namespace qiao {
	class ShaderVertexAttributeCollection: public std::map<std::string, ShaderVertexAttribute*> {};
}