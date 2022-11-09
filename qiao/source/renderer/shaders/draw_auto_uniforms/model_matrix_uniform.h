#pragma once

#include "draw_auto_uniform.h"
#include "../uniform.h"

namespace qiao {
	class ModelMatrixUniform : public DrawAutoUniform {
	public:
		ModelMatrixUniform(Uniform* uniform);

		virtual void set(Context* context, DrawState* drawState);

	private:
		Uniform* _uniform;
	};
}