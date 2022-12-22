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
		
		/*qiao::Mesh mesh;
		mesh.setPrimitiveType(GL_TRIANGLES);

		qiao::VertexAttributeVector4F* attributeVector4F = new qiao::VertexAttributeVector4F("position");
		attributeVector4F->addData(new qiao::Vector4F(0.5f, 0.5f, 0.0f, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(0.5f, -0.5f, 0.0f, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(-0.5f, -0.5f, 0.0f, 1.0));
		attributeVector4F->addData(new qiao::Vector4F(-0.5f, 0.5f, 0.0f, 1.0));
		mesh.getAttributes().push_back(attributeVector4F);

		qiao::IndicesUnsignedShort* indices = new qiao::IndicesUnsignedShort();
		indices->addIndex(0);
		indices->addIndex(1);
		indices->addIndex(3);
		indices->addIndex(1);
		indices->addIndex(2);
		indices->addIndex(3);
		mesh.setIndices(indices);*/

		//qiao::VertexArray* va = _window->getContext()->createVertexArray(mesh, sp->vertexAttributes(), GL_STATIC_DRAW);

		//qiao::RenderState* renderState = new qiao::RenderState();

		//_drawState = new qiao::DrawState(renderState, sp, va);

		//_sceneState = new qiao::SceneState();

        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------
        float vertices[] = {
             0.5f,  0.5f, 0.0f, 1.0,  // top right
             0.5f, -0.5f, 0.0f, 1.0,// bottom right
            -0.5f, -0.5f, 0.0f, 1.0,// bottom left
            -0.5f,  0.5f, 0.0f, 1.0// top left 
        };
        unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
        };
        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);


        // uncomment this call to draw in wireframe polygons.
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        sp->use();
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	}
	~Test() {
		if (_window != nullptr) {
			delete _window;
			_window = nullptr;
		}

		/*if (_drawState != nullptr) {
			delete _drawState;
			_drawState = nullptr;
		}*/
	}

	void run() {
		_window->run();
	}


private:
	void render() {
		/*qiao::Context* context = _window->getContext();

		context->draw(GL_TRIANGLES, _drawState, _sceneState);*/
		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// glBindVertexArray(0); // no need to unbind it every time 
	}

	qiao::Window* _window;
	/*qiao::DrawState* _drawState;
	qiao::SceneState* _sceneState;*/
};

int main() {
	Test test;
	test.run();

	
}