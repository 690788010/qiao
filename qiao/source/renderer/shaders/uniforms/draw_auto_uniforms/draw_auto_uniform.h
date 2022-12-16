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
	 * DrawAutoUniform用于为特定的Uniform自动设置值.
	 */
	class DrawAutoUniform {
	public:
		// 为包含的Uniform自动设置值
		virtual void set(Context* context, DrawState* drawState, SceneState* sceneState) = 0;
	};
}