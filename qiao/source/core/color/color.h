#pragma once

namespace qiao {
	class Color {
	public:
		Color();
		Color(double red, double green, double blue, double alpha);

		double getRed();
		void setRed(double val);

		double getGreen();
		void setGreen(double val);

		double getBlue();
		void setBlue(double val);

		double getAlpha();
		void setAlpha(double val);

		bool equals(Color color);

		static Color WHITE();
		static Color BLACK();

	private:
		double red;
		double green;
		double blue;
		double alpha;
	};
}