#pragma once

#include "../render_state/scissor_test.h"
#include "../render_state/color_mask.h"
#include "../../third_party/glad/include/glad.h"
#include "../../../core/color/color.h"
#include "../render_state/depth_test.h"

namespace qiao {
	enum ClearMask {
		COLOR_BUFFER_BIT = GL_COLOR_BUFFER_BIT,
		DEPTH_BUFFER_BIT = GL_DEPTH_BUFFER_BIT,
		STENCIL_BUFFER_BIT = GL_STENCIL_BUFFER_BIT,
		ALL = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT
	};

	class ClearState {
	public:
		ClearState();

		ScissorTest& getScissorTest();
		void setScissorTest(ScissorTest val);

		ColorMask& getColorMask();
		void setColorMask(ColorMask val);

		GLboolean getDepthMask();
		void setDepthMask(GLboolean flag);

		GLbitfield getClearMask();
		void setClearMask(GLbitfield val);

		Color& getColor();
		void setColor(Color val);

		double getDepth();
		void setDepth(double val);

		int getStencil();
		void setStencil(int val);

	private:
		ScissorTest _scissorTest;		// �ü������������
		ColorMask _colorMask;			// 
		GLboolean _depthMask;			// �Ƿ�������Ȼ����д����

		GLbitfield _clearMask;			// ��ʶ����ĸ�����
		Color _color;				// ��ɫ�������ɫ
		double _depth;					
		int _stencil;
	};
}