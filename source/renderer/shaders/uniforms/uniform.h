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
	 * Uniform类是一个抽象类。它用于表示着色器中的Uniform变量。
	 */
	class Uniform {
		virtual std::string getName() = 0;
		virtual unsigned int getType() = 0;	// 将新值同步到GPU
		virtual int getLocation() = 0;
		virtual void clean() = 0;			
	};

	/**
	 * UniformGeneric类是Uniform类的子类。之所以需要增加一个UniformGeneric类的原因
	 * 是如果Uniform作为泛型类，则UniformCollection中需要明确标明Uniform泛型的类型
	 */
	template <typename T>
	class UniformGeneric : public Uniform {			
	public:
		virtual T& getValue() = 0;
		virtual void setValue(const T& val) = 0;
	};
}
