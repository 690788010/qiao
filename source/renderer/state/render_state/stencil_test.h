#pragma once


namespace qiao {
	class StencilTest {
	public:
		StencilTest();

		bool getEnabled();
		void setEnabled(bool val);

	private:
		bool _enabled;
	};
}