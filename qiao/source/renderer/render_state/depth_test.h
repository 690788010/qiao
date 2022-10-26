#pragma once

namespace qiao {
	enum DepthFunc {
		NEVER,
		LESS,
		EQUAL,
		LEQUAL,
		GREATER,
		NOTEQUAL,
		GEQUAL,
		ALWAYS
	};

	class DepthRange {
	public:
		DepthRange(double near = 0.0, double far = 1.0);

		double getNear();
		void setNear(double val);

		double getFar();
		void setFar(double val);

	private:
		double near;
		double far;
	};

	class DepthTest {
	public:
		DepthTest();

		bool getEnabled();
		void setEnabled(bool val);

		DepthFunc getDepthFunc();
		void setDepthFunc(DepthFunc val);

		DepthRange& getDepthRange();
		void setDepthRange(DepthRange val);

		bool getDepthMask();
		void setDepthMask(bool val);

	private:
		bool enabled;
		DepthFunc depthFunc;
		DepthRange depthRange;
		bool depthMask;
	};
}