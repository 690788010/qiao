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
	 * UniformMatrix4D����UniformGeneric������࣬�����ڱ�ʾ��ɫ����4x4�������͵�Uniform������֧��˫���ȸ�������
	 * UniformMatrix4D��ʵ����ICleanable�ӿڣ��Ӷ�Ϊ�ⲿ�ṩ��ֵͬ����GPU��clean������
	 */
	class UniformMatrix4D : public UniformGeneric<Matrix4D>, public ICleanable {
	public:
		UniformMatrix4D(std::string name, int location, unsigned int type, ICleanableObserver* observer);

		virtual std::string getName();
		virtual unsigned int getType();
		virtual int getLocation();
		virtual Matrix4D& getValue();
		virtual void setValue(const Matrix4D& val);
		virtual void clean();				// ����ֵͬ����GPU

	private:
		std::string _name;
		int _location;
		unsigned int _type;
		Matrix4D _value;
		bool _dirty;						// �Ƿ���������ֵ����δͬ����GPU
		ICleanableObserver* _observer;		// ����ShaderProgram����ָ��
	};
}
