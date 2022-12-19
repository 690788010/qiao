/*****************************************************************//**
 * \file   matrix4f.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

namespace qiao {
	/**
	 * Matrix4F类表示一个单精度浮点数值的4x4矩阵.
	 */
	class Matrix4F {
	public:
		/**
		 * 无参构造函数.
		 * 
		 */
		Matrix4F();

		/**
		 * 构造函数，将矩阵里的各个元素设为同一个值.
		 * 
		 * \param value 矩阵元素值
		 */
		Matrix4F(float value);

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
		Matrix4F(
			float column0row0, float column1row0, float column2row0, float column3row0,
			float column0row1, float column1row1, float column2row1, float column3row1,
			float column0row2, float column1row2, float column2row2, float column3row2,
			float column0row3, float column1row3, float column2row3, float column3row3);

		~Matrix4F();

	private:
		float* _values;			// 存储矩阵的数组（列主序）
	};
}
