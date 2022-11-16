#pragma once

#include <string>
#include "graphics_window.h"
#include "./gl3x/graphics_window_gl3x.h"
#include "buffers/vertex_buffer.h"
#include "gl3x/buffers/vertex_buffer_gl3x.h"
#include "buffers/index_buffer.h"
#include "gl3x/buffers/index_buffer_gl3x.h"

namespace qiao {
	class Device {
	public:
		static GraphicsWindow* createWindow(int width, int height, std::string title, bool isFullScreen = false);

		static VertexBuffer* createVertexBuffer(GLenum usage, GLsizeiptr sizeInBytes);

		static IndexBuffer* createIndexBuffer(GLenum usage, GLsizeiptr sizeInBytes);
	};
}