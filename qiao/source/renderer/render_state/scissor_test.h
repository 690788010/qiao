#pragma once


namespace qiao {
	class ScissorTest {
	public:
		ScissorTest();

		bool getEnabled();
		void setEnabled(bool val);
		int getX();
		void setX(int val);
		int getY();
		void setY(int val);
		int getWidth();
		void setWidth(int val);
		int getHeight();
		void setHeight(int val);

	private:
		bool enabled;
		int x;
		int y;
		int width;
		int height;
	};
}