#pragma once

#include "../../../third_party/glad/include/glad.h"

namespace qiao {
	enum DepthFunc {
		NEVER = GL_NEVER,
		LESS = GL_LESS,
		EQUAL = GL_EQUAL,
		LEQUAL = GL_LEQUAL,
		GREATER = GL_GREATER,
		NOTEQUAL = GL_NOTEQUAL,
		GEQUAL = GL_GEQUAL,
		ALWAYS = GL_ALWAYS
	};

	enum DepthMask {
		TRUE = GL_TRUE,
		FALSE = GL_FALSE
	};

	class DepthTest {
	public:
		DepthTest();

		bool getEnabled();
		void setEnabled(bool val);

		DepthFunc getDepthFunc();
		void setDepthFunc(DepthFunc val);

		DepthMask getDepthMask();
		void setDepthMask(DepthMask val);

		double getNear();
		void setNear(double val);

		double getFar();
		void setFar(double val);

	private:
		bool enabled;
		DepthFunc depthFunc;
		DepthMask depthMask;
		double near;
		double far;
	};
}