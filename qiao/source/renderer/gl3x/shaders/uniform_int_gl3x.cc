
#include <iostream>
#include "uniform_int_gl3x.h"

using namespace qiao;

UniformIntGL3x::UniformIntGL3x(std::string name, int location, unsigned int type, ICleanableObserver* observer) :
	_name{ name }, _location{ location }, _type{ type }, _observer{ observer }
{
	_value = 0.0;
	_dirty = true;
	_observer->notifyDirty(this);
};

std::string UniformIntGL3x::getName() {
	return _name;
};

unsigned int UniformIntGL3x::getType() {
	return _type;
};

int UniformIntGL3x::getLocation() {
	return _location;
};

int UniformIntGL3x::getValue() {
	return _value;
};

void UniformIntGL3x::setValue(int val) {
	if (!_dirty && (_value != val)) {
		_dirty = true;
		_observer->notifyDirty(this);
	}
	_value = val;
};

void UniformIntGL3x::clean() {
	glUniform1f(_location, _value);
	std::cout << _value << std::endl;
	_dirty = false;
};