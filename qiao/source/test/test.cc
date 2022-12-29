
#include <iostream>
#include <filesystem>
#include <direct.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../../third_party/stb_image/stb_image.h"
#include "../renderer/buffers/write_pixel_buffer.h"
#include "../renderer/window.h"

int main() {
	char* cwd;
	cwd = _getcwd(NULL, 0);
	std::string path = cwd;
	path += "/assets/textures/NaturalEarth/NE2_50M_SR_W.jpg";
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (!data) {
		//throw std::invalid_argument("Failed to load texture");
		std::cout << "Failed to load texture" << std::endl;
	}
	qiao::Window* window = new qiao::Window(800, 600, "qiao", false);
	unsigned int size = width * height * nrChannels;
	qiao::WritePixelBuffer* write_pixel_buffer = new qiao::WritePixelBuffer(GL_STATIC_DRAW, size);
	write_pixel_buffer->copyFromSystemMemory(data, 0, size);
	
	stbi_image_free(data);
	delete write_pixel_buffer;
	delete window;
	std::cout << path << std::endl;
}
