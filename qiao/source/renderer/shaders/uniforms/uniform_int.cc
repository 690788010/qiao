#include <iostream>
#include "uniform_int.h"

using namespace qiao;

UniformInt::UniformInt(std::string name, int location, unsigned int type, ICleanableObserver* observer) :
	_name{ name }, _location{ location }, _type{ type }, _observer{ observer }
{
	_value = 0.0;
	_dirty = true;
	_observer->notifyDirty(this);
};

std::string UniformInt::getName() {
	return _name;
};

unsigned int UniformInt::getType() {
	return _type;
};

int UniformInt::getLocation() {
	return _location;
};

int& UniformInt::getValue() {
	return _value;
};

void UniformInt::setValue(const int& val) {
	if (!_dirty && (_value != val)) {
		_dirty = true;
		_observer->notifyDirty(this);	// 通知ShaderProgram有Uniform设置了新值而未同步到GPU
	}
	_value = val;
};

void UniformInt::clean() {
	glUniform1i(_location, _value);
	_dirty = false;
};