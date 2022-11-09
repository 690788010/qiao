#include "model_matrix_uniform_factory.h"

using namespace qiao;

std::string ModelMatrixUniformFactory::getName() {
	return "og_modelMatrix";
};

ModelMatrixUniform* ModelMatrixUniformFactory::create(Uniform* uniform) {
	return new ModelMatrixUniform(uniform);
};