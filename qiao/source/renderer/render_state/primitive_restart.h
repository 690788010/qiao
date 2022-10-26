#pragma once


namespace qiao {
	class PrimitiveRestart {
	public:
		PrimitiveRestart();

		bool getEnabled();
		void setEnabled(bool val);
		int getIndex();
		void setIndex(int val);

	private:
		bool enabled;
		int index;
	};
}