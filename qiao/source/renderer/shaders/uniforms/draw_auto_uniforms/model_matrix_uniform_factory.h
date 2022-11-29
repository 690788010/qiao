#pragma once

#include "draw_auto_uniform_factory.h"
#include "model_matrix_uniform.h"

namespace qiao {
	class ModelMatrixUniformFactory : public DrawAutoUniformFactory {
	public:
		virtual std::string getName();
		virtual ModelMatrixUniform* create(Uniform* uniform);
	};
}