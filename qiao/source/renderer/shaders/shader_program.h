#pragma once

#include "shader_vertex_attribute_collection.h"

namespace qiao {
	class ShaderProgram {
	public:
		virtual ~ShaderProgram();
		virtual void use() = 0;
		virtual ShaderVertexAttributeCollection vertexAttributes() = 0;
	};
}