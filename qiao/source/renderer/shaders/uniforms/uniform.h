#pragma once

#include <string>

namespace qiao {
	class Uniform {
		virtual std::string getName() = 0;
		virtual unsigned int getType() = 0;	// ����ֵͬ����GPU
		virtual int getLocation() = 0;
		virtual void clean() = 0;			
	};

	// ֮������Ҫ����һ��UniformGeneric���ԭ�������Uniform��Ϊ�����࣬
	// ��UniformCollection����Ҫ��ȷ����Uniform���͵�����
	template <typename T>
	class UniformGeneric : public Uniform {			
	public:
		virtual T getValue() = 0;
		virtual void setValue(T val) = 0;
	};
}
