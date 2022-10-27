#pragma once

#include "../../../third_party/glad/include/glad.h"

namespace qiao {
	enum BlendingFactor {
        ZERO = GL_ZERO,
        ONE = GL_ONE,
        SRC_COLOR = GL_COLOR,
        ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
        DST_COLOR = GL_DST_COLOR,
        ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
        SRC_ALPHA = GL_SRC_ALPHA,
        ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
        DST_ALPHA = GL_DST_ALPHA,
        ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
        CONSTANT_COLOR = GL_CONSTANT_COLOR,
        ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
        CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
        ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA
	};

    enum BlendEquation {
        FUNC_ADD = GL_FUNC_ADD,
        FUNC_SUBTRACT = GL_FUNC_SUBTRACT,
        FUNC_REVERSE_SUBTRACT = GL_FUNC_REVERSE_SUBTRACT,
        MIN = GL_MIN,
        MAX = GL_MAX
    };

	class Blending {
	public:
		Blending();

        bool getEnabled();
        void setEnabled(bool val);

        BlendingFactor getSrcRGB();
        void setSrcRGB(BlendingFactor val);

        BlendingFactor getDstRGB();
        void setDstRGB(BlendingFactor val);

        BlendingFactor getSrcAlpha();
        void setSrcAlpha(BlendingFactor val);

        BlendingFactor getDstAlpha();
        void setDstApha(BlendingFactor val);

        BlendEquation getRgbEquation();
        void setRgbEquation(BlendEquation val);

        BlendEquation getAlphaEquation();
        void setAlphaEquation(BlendEquation val);

	private:
		bool enabled;
        BlendingFactor srcRGB;
        BlendingFactor dstRGB;
        BlendingFactor srcAlpha;
        BlendingFactor dstAlpha;
        BlendEquation rgbEquation;
        BlendEquation alphaEquation;
	};
}