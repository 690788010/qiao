#pragma once

#include "primitive_restart.h"
#include "cull_face.h"
#include "stencil_test.h"
#include "depth_test.h"

namespace qiao {
	enum ProgramPointSize {
		Enabled,
		Disabled
	};

	enum PolygonMode {
		POINT,
		LINE,
		FILL
	};

	class RenderState {
	public:
		RenderState();

		PrimitiveRestart& getPrimitiveRestart();
		void setPrimitiveRestart(PrimitiveRestart val);

		CullFace& getCullFace();
		void setCullFace(CullFace val);

		ProgramPointSize& getProgramPointSize();
		void setProgramPointSize(ProgramPointSize val);

		PolygonMode& getPolygonMode();
		void setPolygonMode(PolygonMode val);

		StencilTest& getStencilTest();
		void setStencilTest(StencilTest val);

		DepthTest& getDepthTest();
		void setDepthTest(DepthTest val);

	private:
		PrimitiveRestart primitiveRestart;
		CullFace cullFace;
		ProgramPointSize programPointSize;
		PolygonMode polygonMode;
		StencilTest stencilTest;
		DepthTest depthTest;
	};
}