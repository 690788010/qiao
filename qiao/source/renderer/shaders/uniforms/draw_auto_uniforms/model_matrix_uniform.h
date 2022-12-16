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
	 * ModelMatrixUniform��DrawAutoUniform������࣬������Ϊ��ģ�����Ӧ��Uniform�Զ�����ֵ.
	 */
	class ModelMatrixUniform : public DrawAutoUniform {
	public:
		/**
		 * ���캯��.
		 * 
		 * \param uniform ��ʾ��ģ�����Uniform
		 */
		ModelMatrixUniform(Uniform* uniform);

		// Ϊ����Ľ�ģ�����Uniform�Զ�����ֵ
		virtual void set(Context* context, DrawState* drawState, SceneState* sceneState);

	private:
		Uniform* _uniform;
	};
}