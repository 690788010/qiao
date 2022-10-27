#pragma once

#include "primitive_restart.h"
#include "cull_face.h"
#include "scissor_test.h"
#include "stencil_test.h"
#include "depth_test.h"
#include "blending.h"

namespace qiao {
	enum ProgramPointSize {
		Enabled = true,
		Disabled = false
	};

	enum PolygonMode {
		POINT = GL_POINT,
		LINE = GL_LINE,
		FILL = GL_FILL
	};

	class RenderState {
	public:
		RenderState();

		PrimitiveRestart& getPrimitiveRestart();
		void setPrimitiveRestart(PrimitiveRestart val);

		CullFace& getCullFace();
		void setCullFace(CullFace val);

		ProgramPointSize getProgramPointSize();
		void setProgramPointSize(ProgramPointSize val);

		ScissorTest& getScissorTest();
		void setScissorTest(ScissorTest val);

		PolygonMode& getPolygonMode();
		void setPolygonMode(PolygonMode val);

		StencilTest& getStencilTest();
		void setStencilTest(StencilTest val);

		DepthTest& getDepthTest();
		void setDepthTest(DepthTest val);

		Blending& getBlending();
		void setBlending(Blending val);

	private:
		PrimitiveRestart primitiveRestart;
		CullFace cullFace;
		ProgramPointSize programPointSize;
		ScissorTest scissorTest;
		PolygonMode polygonMode;
		StencilTest stencilTest;
		DepthTest depthTest;
		Blending blending;
	};
}