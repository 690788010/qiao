#pragma once


namespace qiao {
	class ScissorTest {
	public:
		ScissorTest();

		bool getEnabled();
		void setEnabled(bool val);
		int getX();
		int getY();
		int getWidth();
		int getHeight();

	private:
		bool enabled;
		int x;
		int y;
		int width;
		int height;
	};
}