#include <iostream>
#include <functional>

#include "../renderer/window.h"
#include "../renderer/shaders/shader_program.h"
#include "../core/geometry/mesh.h"
#include "../renderer/vertex_array/vertex_array.h"
#include "../renderer/context.h"

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
		_sp = new qiao::ShaderProgram(vs, fs);
		
		qiao::Mesh* mesh = new qiao::Mesh();
		mesh->setPrimitiveType(GL_TRIANGLES);

		qiao::VertexAttributeVector4F* attributeVector4F = new qiao::VertexAttributeVector4F("position");
		attributeVector4F->addData(new qiao::Vector4F(0, 0, 0, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(1, 0, 0, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(0, 0, 1, 1.0));
		mesh->getAttributes()->push_back(attributeVector4F);

		qiao::IndicesUnsignedShort* indices = new qiao::IndicesUnsignedShort();
		indices->addIndex(0);
		indices->addIndex(1);
		indices->addIndex(2);
		mesh->setIndices(indices);

		qiao::Context* context = _window->getContext();

		qiao::VertexArray* va = context->createVertexArray(mesh, _sp->vertexAttributes(), GL_STATIC_DRAW);

		delete mesh;
	}
	~Test() {
		if (_window != nullptr) {
			delete _window;
			_window = nullptr;
		}

		if (_sp != nullptr) {
			delete _sp;
			_sp = nullptr;
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
	qiao::ShaderProgram* _sp;
};

int main() {
	Test test;
	test.run();

	
}