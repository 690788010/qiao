#pragma once

#include "./clear_state.h"
#include "./draw_state.h"
#include "scene/scene_state.h"

namespace qiao {
	class Context {
	public:
		virtual void clear(ClearState* clearState) = 0;
		virtual void draw(DrawState* drawState, SceneState* sceneState) = 0;
	};
}