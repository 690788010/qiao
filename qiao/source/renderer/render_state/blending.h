#pragma once


namespace qiao {
	enum BlendingFactor {
        ZERO,
        ONE,
        SRC_COLOR,
        ONE_MINUS_SRC_COLOR,
        DST_COLOR,
        ONE_MINUS_DST_COLOR,
        SRC_ALPHA,
        ONE_MINUS_SRC_ALPHA,
        DST_ALPHA,
        ONE_MINUS_DST_ALPHA,
        CONSTANT_COLOR,
        ONE_MINUS_CONSTANT_COLOR,
        CONSTANT_ALPHA,
        ONE_MINUS_CONSTANT_ALPHA
	};

    enum BlendEquation {
        FUNC_ADD,
        FUNC_SUBTRACT,
        FUNC_REVERSE_SUBTRACT,
        MIN,
        MAX
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