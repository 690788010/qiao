
#include <iostream>
#include "uniform_float_gl3x.h"

using namespace qiao;

UniformFloatGL3x::UniformFloatGL3x(std::string name, int location, unsigned int type, ICleanableObserver* observer) :
	_name{ name }, _location{ location }, _type{ type }, _observer{observer}
{
	_value = 0.0;
	_dirty = true;
	_observer->notifyDirty(this);
};

std::string UniformFloatGL3x::getName() {
	return _name;
};

unsigned int UniformFloatGL3x::getType() {
	return _type;
};

int UniformFloatGL3x::getLocation() {
	return _location;
};

float UniformFloatGL3x::getValue() {
	return _value;
};

void UniformFloatGL3x::setValue(float val) {
	if (!_dirty && (_value != val)) {
		_dirty = true;
		_observer->notifyDirty(this);
	}
	_value = val;
};

void UniformFloatGL3x::clean() {
	glUniform1f(_location, _value);
	_dirty = false;
};