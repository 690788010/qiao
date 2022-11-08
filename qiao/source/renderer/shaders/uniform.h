#pragma once

#include <string>

namespace qiao {
	class Uniform {
		virtual std::string getName() = 0;
		virtual unsigned int getType() = 0;
	};

	template <typename T>
	class UniformGeneric : public Uniform {
	public:
		virtual int getLocation() = 0;
		virtual T getValue() = 0;
		virtual void setValue(T val) = 0;
	};
}
