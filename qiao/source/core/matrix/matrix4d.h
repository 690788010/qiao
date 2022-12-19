/*****************************************************************//**
 * \file   matrix4d.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

namespace qiao {
	/**
	 * Matrix4D类表示一个双精度浮点数值的4x4矩阵.
	 */
	class Matrix4D {
	public:
		/**
		 * 无参构造函数.
		 *
		 */
		Matrix4D();

		/**
		 * 构造函数，将矩阵里的各个元素设为同一个值.
		 *
		 * \param value 矩阵元素值
		 */
		Matrix4D(double value);

		/**
		 * 构造函数，明确设定矩阵里各个元素的值.
		 *
		 * \param column0row0
		 * \param column1row0
		 * \param column2row0
		 * \param column3row0
		 * \param column0row1
		 * \param column1row1
		 * \param column2row1
		 * \param column3row1
		 * \param column0row2
		 * \param column1row2
		 * \param column2row2
		 * \param column3row2
		 * \param column0row3
		 * \param column1row3
		 * \param column2row3
		 * \param column3row3
		 */
		Matrix4D(
			double column0row0, double column1row0, double column2row0, double column3row0,
			double column0row1, double column1row1, double column2row1, double column3row1,
			double column0row2, double column1row2, double column2row2, double column3row2,
			double column0row3, double column1row3, double column2row3, double column3row3);

		~Matrix4D();

		static Matrix4D Identity();


	private:
		double* _values;			// 存储矩阵的数组（列主序）
	};
}
