#pragma once


namespace qiao {
	class Rectangle {
	public:
		Rectangle(int x, int y, int width, int height);

		int getX();
		int getY();

		int getWidth();
		int getHeight();

	private:
		int x;
		int y;
		int width;
		int height;
	};

	class ScissorTest {
	public:
		ScissorTest();

		bool getEnabled();
		void setEnabled(bool val);

		Rectangle& getRectangle();
		void setRectangle(Rectangle val);

	private:
		bool enabled;
		Rectangle rectangle;
	};
}