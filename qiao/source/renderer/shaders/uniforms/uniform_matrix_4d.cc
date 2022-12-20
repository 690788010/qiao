/*****************************************************************//**
 * \file   uniform_matrix_4d.cc
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#include "uniform_matrix_4d.h"

using namespace qiao;

UniformMatrix4D::UniformMatrix4D(std::string name, int location, unsigned int type, ICleanableObserver* observer)
	: _name{ name }, _location{ location }, _type{ type }, _observer{ observer }, _value{ Matrix4D::Identity() }
{
	_dirty = true;
	_observer->notifyDirty(this);
};

std::string UniformMatrix4D::getName() {
	return _name;
};

unsigned int UniformMatrix4D::getType() {
	return _type;
};

int UniformMatrix4D::getLocation() {
	return _location;
};

Matrix4D& UniformMatrix4D::getValue() {
	return _value;
};

void UniformMatrix4D::setValue(const Matrix4D& val) {
	if (!_dirty && (_value != val)) {
		_dirty = true;
		_observer->notifyDirty(this);		// 通知ShaderProgram有Uniform设置了新值而未同步到GPU
	}
	_value = std::move(val);
};

void UniformMatrix4D::clean() {
	glUniformMatrix4fv(_location, 1, false, (GLfloat*)_value.getValues());	// 将新值同步到GPU
	_dirty = false;
};				
