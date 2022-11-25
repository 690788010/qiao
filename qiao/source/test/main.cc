#include <iostream>
#include <functional>

#include "../renderer/window.h"

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
		_window = new qiao::Window(800, 600, "qiao");
		Wrapper::broker_func = std::bind(&Test::render, this);
		// Wrapper wrapper;
		_window->render = Wrapper::wrapper_func;
	}
	~Test() {
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
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	qiao::Window* _window;
};

int main() {
	Test test;
	test.run();

	
}