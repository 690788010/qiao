#pragma once

#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	enum CullFaceMode {
		FRONT = GL_FRONT,
		BACK = GL_BACK,
		FRONT_AND_BACK = GL_FRONT_AND_BACK
	};

	enum FrontFaceMode {
		CW = GL_CW,
		CCW = GL_CCW
	};

	class CullFace {
	public:
		CullFace();
		bool getEnabled();
		void setEnabled(bool val);
		CullFaceMode getCullFaceMode();
		void setCullFaceMode(CullFaceMode val);
		FrontFaceMode getFrontFaceMode();
		void setFrontFaceMode(FrontFaceMode val);

	private:
		bool enabled;
		CullFaceMode cullFaceMode;
		FrontFaceMode frontFaceMode;
	};
}