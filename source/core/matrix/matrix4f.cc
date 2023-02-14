/*****************************************************************//**
 * \file   matrix4f.cc
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#include "matrix4f.h"

using namespace qiao;

Matrix4F::Matrix4F() {
	_values = new float[16];
	for (int i = 0; i < 16; i++) {
		_values[i] = 0.0;
	}
};

Matrix4F::Matrix4F(float value) {
	_values = new float[] {
		value, value, value, value,
		value, value, value, value,
		value, value, value, value,
		value, value, value, value
	};
};

Matrix4F::Matrix4F(
	float column0row0, float column1row0, float column2row0, float column3row0,
	float column0row1, float column1row1, float column2row1, float column3row1,
	float column0row2, float column1row2, float column2row2, float column3row2,
	float column0row3, float column1row3, float column2row3, float column3row3)
{
	_values = new float[] {
		column0row0, column0row1, column0row2, column0row3,
		column1row0, column1row1, column1row2, column1row3,
		column2row0, column2row1, column2row2, column2row3,
		column3row0, column3row1, column3row2, column3row3
	};
};

Matrix4F::~Matrix4F() {
	if (_values != nullptr) {
		delete[] _values;
		_values = nullptr;
	}
};
