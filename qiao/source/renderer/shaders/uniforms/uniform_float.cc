#include <iostream>
#include "uniform_float.h"

using namespace qiao;

UniformFloat::UniformFloat(std::string name, int location, unsigned int type, ICleanableObserver* observer) :
	_name{ name }, _location{ location }, _type{ type }, _observer{observer}
{
	_value = 0.0;
	_dirty = true;
	_observer->notifyDirty(this);
};

std::string UniformFloat::getName() {
	return _name;
};

unsigned int UniformFloat::getType() {
	return _type;
};

int UniformFloat::getLocation() {
	return _location;
};

float UniformFloat::getValue() {
	return _value;
};

void UniformFloat::setValue(float val) {
	if (!_dirty && (_value != val)) {
		_dirty = true;
		_observer->notifyDirty(this);		// 通知ShaderProgram有Uniform设置了新值而未同步到GPU
	}
	_value = val;
};

void UniformFloat::clean() {
	glUniform1f(_location, _value);
	_dirty = false;
};