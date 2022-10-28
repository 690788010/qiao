#include <iostream>
#include <functional>

#include "../renderer/device.h"
#include "../renderer/gl3x/graphics_window_gl3x.h"
#include "../renderer/draw_state.h"

typedef std::function<void()> Functional;

class Wrapper {
public:
	static int va1;
	//static std::function<void()> broker_func; //必须为inline，否则无法解析
	static Functional broker_func;
	static void wrapper_func() {
		Wrapper::broker_func();
	}
	void reset() {
		va1 = 1000;
	}
	void setFunc(Functional val) {
		broker_func = nullptr;
	}
};

int Wrapper::va1 = 100;
Functional broker_func = nullptr;

class Test {
public:
	Test() {
		_window = qiao::Device::createWindow(800, 600, "qiao");
		std::cout << Wrapper::va1 << std::endl;
		Wrapper wrapper;
		wrapper.reset();
		Wrapper::va1 = 10000;
		std::cout << Wrapper::va1 << std::endl;
		//Wrapper::broker_func = std::bind(&Test::render, this);
		Functional broker_func = std::bind(&Test::render, this);
		wrapper.setFunc(broker_func);
		/*Wrapper wrapper;
		*/
		//_window->render = Wrapper::wrapper_func;

		//_drawState = new qiao::DrawState();
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

	static std::function<void()> broker_func; //必须为inline，否则无法解析

	void run() {
		_window->run();
	}

private:
	void render() {
		//qiao::Context context = _window->getContext();
		//context.draw(_drawState);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	qiao::GraphicsWindow* _window;
	qiao::DrawState* _drawState;
};

int main() {
	Test test;
	//test.run();
}