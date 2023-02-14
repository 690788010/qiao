/*****************************************************************//**
 * \file   draw_auto_uniform.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once
#include "../../../scene/scene_state.h"

namespace qiao {
	class Context;
	class DrawState;

	/**
	 * DrawAutoUniform����Ϊ�ض���Uniform�Զ�����ֵ.
	 */
	class DrawAutoUniform {
	public:
		// Ϊ������Uniform�Զ�����ֵ
		virtual void set(Context* context, DrawState* drawState, SceneState* sceneState) = 0;
	};
}