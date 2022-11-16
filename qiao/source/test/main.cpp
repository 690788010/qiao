#include <iostream>
#include <functional>

#include "../renderer/device.h"
#include "../renderer/gl3x/graphics_window_gl3x.h"
#include "../renderer/render_state/render_state.h"
#include "../renderer/gl3x/shaders/shader_program_gl3x.h"
#include "../renderer/buffers/vertex_buffer.h"
#include "../renderer/buffers/index_buffer.h"


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
		fs += "\nuniform float color;";
		fs += "\nvoid main() {";
		fs += "\n	fragColor = vec4(color, 0.0, 0.0, 1.0);";
		fs += "\n}";

		_vertexBuffer = qiao::Device::createVertexBuffer(GL_STATIC_DRAW, 32);
		float data[] = {1.0, 2.0, 3.0, 4.0};
		_vertexBuffer->copyFromSystemMemory(data, 0, 16);
		float data2[4];
		 _vertexBuffer->copyToSystemMemory(data2, 0, sizeof(data2));
		std::cout << data2[3] << std::endl;
		short index[] = { 5, 6, 7, 8 };
		_indexBuffer = qiao::Device::createIndexBuffer(GL_STATIC_DRAW, sizeof(index));
		_indexBuffer->copyFromSystemMemory(index, qiao::IndexBufferDataType::UNSIGNED_SHORT, 0, sizeof(index));
		short index2[4];
		_indexBuffer->copyToSystemMemory(index2, 0, sizeof(index2));
		std::cout << index2[3] << std::endl;


		qiao::RenderState* rs = new qiao::RenderState();
		qiao::ShaderProgramGL3x* sp = new qiao::ShaderProgramGL3x(vs, fs);
		_sceneState = new qiao::SceneState();

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
		if (_vertexBuffer != nullptr) {
			delete _vertexBuffer;
			_vertexBuffer = nullptr;
		}
		if (_indexBuffer != nullptr) {
			delete _indexBuffer;
			_indexBuffer = nullptr;
		}
	}

	void run() {
		_window->run();
	}

private:
	void render() {
		qiao::Context* context = _window->getContext();
		context->clear(_clearState);
		context->draw(_drawState, _sceneState);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	qiao::GraphicsWindow* _window;
	qiao::ClearState* _clearState;
	qiao::DrawState* _drawState;
	qiao::SceneState* _sceneState;
	qiao::VertexBuffer* _vertexBuffer;
	qiao::IndexBuffer* _indexBuffer;
};

int main() {
	Test test;
	test.run();
}