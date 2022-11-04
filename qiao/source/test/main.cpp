#include <iostream>
#include <functional>

#include "../renderer/device.h"
#include "../renderer/gl3x/graphics_window_gl3x.h"
#include "../renderer/render_state/render_state.h"
#include "../renderer/gl3x/shaders/shader_program_gl3x.h"


class Wrapper {
public:
	static std::function<void()> broker_func;
	static void wrapper_func() {
		Wrapper::broker_func();
	}
};

std::function<void()> Wrapper::broker_func = nullptr;

class Test {
public:
	Test() {

		_window = qiao::Device::createWindow(800, 600, "qiao");
		Wrapper::broker_func = std::bind(&Test::render, this);
		// Wrapper wrapper;
		_window->render = Wrapper::wrapper_func;

		_clearState = new qiao::ClearState();

		std::string vs =
			  "in vec4 position;";
		vs += "\nvoid main() {";
		vs += "\n	gl_Position = position;";
		vs += "\n}";
		std::string fs = "out vec4 fragColor;";
		fs += "\nvoid main() {";
		fs += "\n	fragColor = vec4(0.0, 0.0, 0.0, 1.0);";
		fs += "\n}";

		qiao::RenderState* rs = new qiao::RenderState();
		
		qiao::ShaderProgramGL3x* sp = new qiao::ShaderProgramGL3x(vs, fs);
		_drawState = new qiao::DrawState(rs, sp);
	}

	~Test() {
		if (_drawState != nullptr) {
			delete _drawState;
			_drawState = nullptr;
		}
		if (_window != nullptr) {
			delete _window;
			_window = nullptr;
		}
	}

	void run() {
		_window->run();
	}

private:
	void render() {
		qiao::Context* context = _window->getContext();
		context->clear(_clearState);
		context->draw(_drawState);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	qiao::GraphicsWindow* _window;
	qiao::ClearState* _clearState;
	qiao::DrawState* _drawState;
};

int main() {
	Test test;
	test.run();
}