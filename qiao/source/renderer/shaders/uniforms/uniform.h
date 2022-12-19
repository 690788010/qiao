/*****************************************************************//**
 * \file   uniform.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include <string>

namespace qiao {
	/**
	 * Uniform����һ�������ࡣ�����ڱ�ʾ��ɫ���е�Uniform������
	 */
	class Uniform {
		virtual std::string getName() = 0;
		virtual unsigned int getType() = 0;	// ����ֵͬ����GPU
		virtual int getLocation() = 0;
		virtual void clean() = 0;			
	};

	/**
	 * UniformGeneric����Uniform������ࡣ֮������Ҫ����һ��UniformGeneric���ԭ��
	 * �����Uniform��Ϊ�����࣬��UniformCollection����Ҫ��ȷ����Uniform���͵�����
	 */
	template <typename T>
	class UniformGeneric : public Uniform {			
	public:
		virtual T& getValue() = 0;
		virtual void setValue(const T& val) = 0;
	};
}
