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
	 * Matrix4F���ʾһ�������ȸ�����ֵ��4x4����.
	 */
	class Matrix4F {
	public:
		/**
		 * �޲ι��캯��.
		 * 
		 */
		Matrix4F();

		/**
		 * ���캯������������ĸ���Ԫ����Ϊͬһ��ֵ.
		 * 
		 * \param value ����Ԫ��ֵ
		 */
		Matrix4F(float value);

		/**
		 * ���캯������ȷ�趨���������Ԫ�ص�ֵ.
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
		float* _values;			// �洢��������飨������
	};
}
