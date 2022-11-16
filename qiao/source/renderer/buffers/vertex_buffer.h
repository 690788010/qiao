#pragma once

namespace qiao {
	class VertexBuffer {
	public:
		virtual void copyFromSystemMemory(void* data, unsigned int offset, unsigned int size) = 0;
		virtual void copyToSystemMemory(void* data, unsigned int offset, unsigned int size) = 0;

		virtual unsigned int getUsage() = 0;
		virtual unsigned int getSizeInBytes() = 0;
	};
}