#pragma once
#include "../../../scene/scene_state.h"

namespace qiao {
	class Context;
	class DrawState;

	class DrawAutoUniform {
	public:
		virtual void set(Context* context, DrawState* drawState, SceneState* sceneState) = 0;
	};
}