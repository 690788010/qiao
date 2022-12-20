/*****************************************************************//**
 * \file   model_matrix_uniform.cc
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#include "model_matrix_uniform.h"

using namespace qiao;

ModelMatrixUniform::ModelMatrixUniform(Uniform* uniform) {
	_uniform = uniform;
};

void ModelMatrixUniform::set(Context* context, DrawState* drawState, SceneState* sceneState) {
	((UniformMatrix4D*)_uniform)->setValue(sceneState->getModelMatrix());
};