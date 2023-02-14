/*****************************************************************//**
 * \file   model_matrix_uniform_factory.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "draw_auto_uniform_factory.h"
#include "model_matrix_uniform.h"

namespace qiao {
	/**
	 * ModelMatrixUniformFactory类是DrawAutoUniformFactory类的子类
	 * ModelMatrixUniformFactory类是用于创建对应的ModelMatrixUniform对象的工厂类，.
	 */
	class ModelMatrixUniformFactory : public DrawAutoUniformFactory {
	public:
		/**
		 * 用于返回对应的name.
		 *
		 * \return std::string
		 */
		virtual std::string getName();

		/**
		 * 用于创建对应的ModelMatrixUniform.
		 *
		 * \param Uniform
		 * \return ModelMatrixUniform*
		 */
		virtual ModelMatrixUniform* create(Uniform* uniform);
	};
}