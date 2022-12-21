/*****************************************************************//**
 * \file   uniform_float.h
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
	 * UniformFloat����UniformGeneric������࣬�����ڱ�ʾ��ɫ���и��������͵�Uniform������
	 * UniformFloat��ʵ����ICleanable�ӿڣ��Ӷ�Ϊ�ⲿ�ṩ��ֵͬ����GPU��clean������
	 */
	class UniformFloat : public UniformGeneric<float>, public ICleanable {
	public:
		UniformFloat(std::string name, int location, unsigned int type, ICleanableObserver* observer);

		virtual std::string getName();
		virtual unsigned int getType();
		virtual int getLocation();
		virtual float& getValue();
		virtual void setValue(const float& val);

		virtual void clean();				// ����ֵͬ����GPU

	private:
		std::string _name;
		int _location;
		unsigned int _type;
		float _value;
		bool _dirty;						// �Ƿ���������ֵ����δͬ����GPU
		ICleanableObserver* _observer;		// ����ShaderProgram����ָ��
	};
}