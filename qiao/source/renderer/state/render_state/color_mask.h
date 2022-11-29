#pragma once

namespace qiao {
	class ColorMask {
	public:
		ColorMask();
		ColorMask(bool red, bool green, bool blue, bool alpha);

		bool getRed();
		void setRed(bool val);

		bool getGreen();
		void setGreen(bool val);

		bool getBlue();
		void setBlue(bool val);

		bool getAlpha();
		void setAlpha(bool val);

		bool equals(ColorMask obj);

	private:
		bool red;
		bool green;
		bool blue;
		bool alpha;
	};
}