#pragma once

#include "../../../../third_party/glad/include/glad.h"

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

	class DepthTest {
	public:
		DepthTest();

		bool getEnabled();
		void setEnabled(bool val);

		DepthFunc getDepthFunc();
		void setDepthFunc(DepthFunc val);

		GLboolean getDepthMask();
		void setDepthMask(GLboolean flag);

		double getNear();
		void setNear(double val);

		double getFar();
		void setFar(double val);

	private:
		bool _enabled;
		DepthFunc _depthFunc;
		GLboolean _depthMask;		// 是否开启对深度缓冲的写操作
		double _near;
		double _far;
	};
}