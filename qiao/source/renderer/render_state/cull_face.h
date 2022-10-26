#pragma once

namespace qiao {
	enum CullFaceMode {
		FRONT,
		BACK,
		FRONT_AND_BACK
	};

	enum FrontFaceMode {
		CW,
		CCW
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