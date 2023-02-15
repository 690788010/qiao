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
	 * UniformInt����UniformGeneric������࣬�����ڱ�ʾ��ɫ�����������͵�Uniform������
	 * UniformInt��ʵ����ICleanable�ӿڣ��Ӷ�Ϊ�ⲿ�ṩ��ֵͬ����GPU��clean������
	 */
	class UniformInt : public UniformGeneric<int>, public ICleanable {
	public:
		UniformInt(std::string name, int location, unsigned int type, ICleanableObserver* observer);

		virtual std::string getName();
		virtual unsigned int getType();
		virtual int getLocation();
		virtual int& getValue();
		virtual void setValue(const int& val);

		virtual void clean();			// ����ֵͬ����GPU

	private:
		std::string _name;
		int _location;
		unsigned int _type;
		int _value;
		bool _dirty;				    // �Ƿ���������ֵ����δͬ����GPU
		ICleanableObserver* _observer;  // ����ShaderProgram����ָ��
	};
}