/*****************************************************************//**
 * \file   uniform_int.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "uniform.h"
#include "../../i_cleanable.h"
#include "../../i_cleanable_observer.h"
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * UniformInt类是UniformGeneric类的子类，它用于表示着色器中整数类型的Uniform变量。
	 * UniformInt类实现了ICleanable接口，从而为外部提供了值同步到GPU的clean函数。
	 */
	class UniformInt : public UniformGeneric<int>, public ICleanable {
	public:
		UniformInt(std::string name, int location, unsigned int type, ICleanableObserver* observer);

		virtual std::string getName();
		virtual unsigned int getType();
		virtual int getLocation();
		virtual int& getValue();
		virtual void setValue(const int& val);

		virtual void clean();			// 将新值同步到GPU

	private:
		std::string _name;
		int _location;
		unsigned int _type;
		int _value;
		bool _dirty;				    // 是否设置了新值而还未同步到GPU
		ICleanableObserver* _observer;  // 保存ShaderProgram对象指针
	};
}