/*****************************************************************//**
 * \file   model_matrix_uniform_factory.cc
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#include "model_matrix_uniform_factory.h"

using namespace qiao;

std::string ModelMatrixUniformFactory::getName() {
	return "og_modelMatrix";
};

ModelMatrixUniform* ModelMatrixUniformFactory::create(Uniform* uniform) {
	return new ModelMatrixUniform(uniform);
};