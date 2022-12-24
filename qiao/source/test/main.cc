#include <iostream>
#include <functional>

#include "../renderer/window.h"
#include "../renderer/shaders/shader_program.h"
#include "../core/geometry/mesh.h"
#include "../renderer/vertex_array/vertex_array.h"
#include "../renderer/context.h"
#include "../core/color/color.h"

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
		_window = new qiao::Window(800, 600, "qiao", false);
		Wrapper::broker_func = std::bind(&Test::render, this);
		// Wrapper wrapper;
		_window->render = Wrapper::wrapper_func;

		std::string vs =
			"layout (location = og_positionVertexLocation) in vec4 position;\n"
			"void main() {\n"
			"	gl_Position = position;\n"
			"}";
		std::string fs = 
			"out vec4 fragColor;\n"
			"void main() {\n"
			"	fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}";
		qiao::ShaderProgram* sp = new qiao::ShaderProgram(vs, fs);
		
		qiao::Mesh mesh;
		mesh.setPrimitiveType(GL_TRIANGLES);

		qiao::VertexAttributeVector4F* attributeVector4F = new qiao::VertexAttributeVector4F("position");
		attributeVector4F->addData(new qiao::Vector4F(0.5f, 0.5f, 0.0f, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(0.5f, -0.5f, 0.0f, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(-0.5f, -0.5f, 0.0f, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(-0.5f, 0.5f, 0.0f, 1.0));
		mesh.getAttributes().push_back(attributeVector4F);

		qiao::IndicesUnsignedShort* indices = new qiao::IndicesUnsignedShort();
		indices->addIndex(3);
		indices->addIndex(1);
		indices->addIndex(0);
		indices->addIndex(3);
		indices->addIndex(2);
		indices->addIndex(1);
		mesh.setIndices(indices);

		qiao::VertexArray* va = _window->getContext()->createVertexArray(mesh, sp->vertexAttributes(), GL_STATIC_DRAW);

		_clearState.setColor(qiao::Color(0.2f, 0.3f, 0.3f, 1.0f));

		qiao::RenderState* rs = new qiao::RenderState();
		_drawState = new qiao::DrawState(rs, sp, va);

		_sceneState = new qiao::SceneState();

	}
	~Test() {
		if (_window != nullptr) {
			delete _window;
			_window = nullptr;
		}

		if (_drawState != nullptr) {
			delete _drawState;
			_drawState = nullptr;
		}
	}

	void run() {
		_window->run();
	}


private:
	void render() {
		qiao::Context* context = _window->getContext();

		// render
		// ------
		/*glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/

		context->clear(_clearState);

		context->draw(GL_TRIANGLES, _drawState, _sceneState);
	}

	qiao::Window* _window;
	qiao::DrawState* _drawState;
	qiao::SceneState* _sceneState;
	qiao::ClearState _clearState;
};

int main() {
	Test test;
	test.run();

	
}