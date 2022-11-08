#pragma once

#include "shader_vertex_attribute_collection.h"
#include "uniform_collection.h"


namespace qiao {
	class ShaderProgram {
	public:
		virtual ~ShaderProgram();
		virtual void use() = 0;
		//virtual void clean(Context* context, DrawState* drawState);
		virtual ShaderVertexAttributeCollection vertexAttributes() = 0;
		virtual UniformCollection uniforms() = 0;
	};
}