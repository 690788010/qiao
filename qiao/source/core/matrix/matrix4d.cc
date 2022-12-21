/*****************************************************************//**
 * \file   matrix4d.cc
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#include "matrix4d.h"

using namespace qiao;

Matrix4D::Matrix4D() {
	_values = new double[16];
	for (int i = 0; i < 16; i++) {
		_values[i] = 0.0;
	}
};

Matrix4D::Matrix4D(double value) {
	_values = new double[] {
		value, value, value, value,
			value, value, value, value,
			value, value, value, value,
			value, value, value, value
	};
};

Matrix4D::Matrix4D(
	double column0row0, double column1row0, double column2row0, double column3row0,
	double column0row1, double column1row1, double column2row1, double column3row1,
	double column0row2, double column1row2, double column2row2, double column3row2,
	double column0row3, double column1row3, double column2row3, double column3row3)
{
	_values = new double[] {
		column0row0, column0row1, column0row2, column0row3,
		column1row0, column1row1, column1row2, column1row3,
		column2row0, column2row1, column2row2, column2row3,
		column3row0, column3row1, column3row2, column3row3
	};
};

Matrix4D::Matrix4D(const Matrix4D& mat4) {
	_values = new double[16];
	for (int i = 0; i < 16; i++) {
		_values[i] = mat4._values[i];
	}
};

Matrix4D::Matrix4D(Matrix4D&& mat4) : _values{ mat4._values } {
	mat4._values = nullptr;
};

Matrix4D::~Matrix4D() {
	if (_values != nullptr) {
		delete[] _values;
		_values = nullptr;
	}
};

Matrix4D& Matrix4D::operator=(const Matrix4D& mat4) {
	for (int i = 0; i < 16; i++) {
		_values[i] = mat4._values[i];
	}
	return *this;
};

Matrix4D& Matrix4D::operator=(Matrix4D&& mat4) {
	delete[] _values;			// 删除旧元素
	// 从mat4中夺取_values
	_values = mat4._values;
	mat4._values = nullptr;
	return *this;

};

Matrix4D Matrix4D::Identity() {
	Matrix4D identity(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);
	return identity;
}

double* Matrix4D::getValues() {
	return _values;
};

bool Matrix4D::operator==(const Matrix4D& mat4d) const {
	double* vals = mat4d._values;
	for (int i = 0; i < 16; i++) {
		if (_values[i] != vals[i]) {
			return false;
		}
	}
	return true;
};

bool Matrix4D::operator!=(const Matrix4D& mat4d) const {
	double* vals = mat4d._values;
	for (int i = 0; i < 16; i++) {
		if (_values[i] != vals[i]) {
			return true;
		}
	}
	return false;
};
