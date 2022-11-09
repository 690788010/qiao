#pragma once

namespace qiao {
	class Context;
	class DrawState;

	class DrawAutoUniform {
	public:
		virtual void set(Context* context, DrawState* drawState) = 0;
	};
}