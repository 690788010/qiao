#pragma once

#include "../../shaders/uniform.h"
#include "../i_cleanable.h"
#include "../i_cleanable_observer.h"
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class UniformIntGL3x : public UniformGeneric<int>, public ICleanable {
	public:
		UniformIntGL3x(std::string name, int location, unsigned int type, ICleanableObserver* observer);

		virtual std::string getName();
		virtual unsigned int getType();
		virtual int getLocation();
		virtual int getValue();
		virtual void setValue(int val);
		virtual void clean();

	private:
		std::string _name;
		int _location;
		unsigned int _type;
		int _value;
		bool _dirty;
		ICleanableObserver* _observer;
	};
}