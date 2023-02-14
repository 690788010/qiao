/*****************************************************************//**
 * \file   uniform_matrix_4d.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "uniform.h"
#include "../../i_cleanable.h"
#include "../../i_cleanable_observer.h"
#include "../../../core/matrix/matrix4d.h"
#include "../../../../third_party/glad/include/glad.h"

namespace qiao {
	/**
	 * UniformMatrix4D类是UniformGeneric类的子类，它用于表示着色器中4x4矩阵类型的Uniform变量，支持双精度浮点数。
	 * UniformMatrix4D类实现了ICleanable接口，从而为外部提供了值同步到GPU的clean函数。
	 */
	class UniformMatrix4D : public UniformGeneric<Matrix4D>, public ICleanable {
	public:
		UniformMatrix4D(std::string name, int location, unsigned int type, ICleanableObserver* observer);

		virtual std::string getName();
		virtual unsigned int getType();
		virtual int getLocation();
		virtual Matrix4D& getValue();
		virtual void setValue(const Matrix4D& val);
		virtual void clean();				// 将新值同步到GPU

	private:
		std::string _name;
		int _location;
		unsigned int _type;
		Matrix4D _value;
		bool _dirty;						// 是否设置了新值而还未同步到GPU
		ICleanableObserver* _observer;		// 保存ShaderProgram对象指针
	};
}
