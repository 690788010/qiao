#pragma once

namespace qiao {
	class ShaderProgram {
	public:
		virtual ~ShaderProgram();
		virtual void use() = 0;
	};
}