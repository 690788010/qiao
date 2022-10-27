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

	class DepthTest {
	public:
		DepthTest();

		bool getEnabled();
		void setEnabled(bool val);

		DepthFunc getDepthFunc();
		void setDepthFunc(DepthFunc val);

		bool getDepthMask();
		void setDepthMask(bool val);

		double getNear();
		void setNear(double val);

		double getFar();
		void setFar(double val);

	private:
		bool enabled;
		DepthFunc depthFunc;
		bool depthMask;
		double near;
		double far;
	};
}