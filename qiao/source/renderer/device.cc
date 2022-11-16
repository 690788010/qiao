#include "device.h"

using namespace qiao;

GraphicsWindow* Device::createWindow(int width, int height, std::string title, bool isFullScreen) {
	return new GraphicsWindowGL3x(width, height, title, isFullScreen);
};

VertexBuffer* Device::createVertexBuffer(GLenum usage, GLsizeiptr sizeInBytes) {
	return new VertexBufferGL3x(usage, sizeInBytes);
};

