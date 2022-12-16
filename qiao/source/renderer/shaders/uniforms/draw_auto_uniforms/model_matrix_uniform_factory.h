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
	 * ModelMatrixUniformFactory����DrawAutoUniformFactory�������
	 * ModelMatrixUniformFactory�������ڴ�����Ӧ��ModelMatrixUniform����Ĺ����࣬.
	 */
	class ModelMatrixUniformFactory : public DrawAutoUniformFactory {
	public:
		/**
		 * ���ڷ��ض�Ӧ��name.
		 *
		 * \return std::string
		 */
		virtual std::string getName();

		/**
		 * ���ڴ�����Ӧ��ModelMatrixUniform.
		 *
		 * \param Uniform
		 * \return ModelMatrixUniform*
		 */
		virtual ModelMatrixUniform* create(Uniform* uniform);
	};
}