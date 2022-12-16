/*****************************************************************//**
 * \file   model_matrix_uniform.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "draw_auto_uniform.h"
#include "../uniform.h"

namespace qiao {
	/**
	 * ModelMatrixUniform是DrawAutoUniform类的子类，它用于为建模矩阵对应的Uniform自动设置值.
	 */
	class ModelMatrixUniform : public DrawAutoUniform {
	public:
		/**
		 * 构造函数.
		 * 
		 * \param uniform 表示建模矩阵的Uniform
		 */
		ModelMatrixUniform(Uniform* uniform);

		// 为保存的建模矩阵的Uniform自动设置值
		virtual void set(Context* context, DrawState* drawState, SceneState* sceneState);

	private:
		Uniform* _uniform;
	};
}