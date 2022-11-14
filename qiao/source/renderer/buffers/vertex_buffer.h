#pragma once

namespace qiao {
	class VertexBuffer {
	public:
		template<typename T>
		void copyFromSystemMemory(void* data) {
			copyFromSystemMemory(data, 0);
		};
		template<typename T>
		void copyFromSystemMemory(T* data, unsigned int offset) {
			copyFromSystemMemory(data, offset, sizeof(data));
		};
		template<typename T>
		void copyFromSystemMemory(T* data, unsigned int offset, unsigned int size);

		void* copyToSystemMemory(unsigned int perElementSize) {
			return copyToSystemMemory(perElementSize, 0, getSizeInBytes());
		};
		virtual void* copyToSystemMemory(unsigned int perElementSize, unsigned int offset, unsigned int size) = 0;

		virtual unsigned int getUsage() = 0;
		virtual unsigned int getSizeInBytes() = 0;
	};
}