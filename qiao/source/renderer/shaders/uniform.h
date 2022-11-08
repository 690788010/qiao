#pragma once

#include <string>

namespace qiao {
	class UniformBase {
		virtual std::string getName() = 0;
		virtual unsigned int getType() = 0;
	};

	template <typename T>
	class Uniform :public UniformBase {
	public:
		virtual int getLocation() = 0;
		virtual T getValue() = 0;
		virtual void setValue(T val) = 0;
	};
}
