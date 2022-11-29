#pragma once

#include <string>
#include "../../../../third_party/glad/include/glad.h"

namespace qiao{
	class ShaderVertexAttribute {
	public:
		ShaderVertexAttribute(std::string name, int location, GLenum type, int length);

		std::string getName();
		int getLocation();
		GLenum getType();
		int getLength();

	private:
		std::string _name;
		int _location;
		GLenum _type;
		int _length;
	};
}