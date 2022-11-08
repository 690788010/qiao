#pragma once

#include "../../shaders/uniform.h"
#include "../i_cleanable.h"
#include "../i_cleanable_observer.h"
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	class UniformFloatGL3x : public UniformGeneric<float>, public ICleanable {
	public:
		UniformFloatGL3x(std::string name, int location, unsigned int type, ICleanableObserver* observer);

		virtual std::string getName();
		virtual unsigned int getType();
		virtual int getLocation();
		virtual float getValue();
		virtual void setValue(float val);
		virtual void clean();

	private:
		std::string _name;
		int _location;
		unsigned int _type;
		float _value;
		bool _dirty;
		ICleanableObserver* _observer;
	};
}