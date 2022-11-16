#pragma once

namespace qiao {
	enum IndexBufferDataType {
		UNSIGNED_BYTE = 1,
		UNSIGNED_SHORT = 2,
		UNSIGNED_INT = 4
	};

	class IndexBuffer {
	public:
		virtual void copyFromSystemMemory(void* data, IndexBufferDataType dataType, unsigned int offset, unsigned int size) = 0;
		virtual void copyToSystemMemory(void* data, unsigned int offset, unsigned int size) = 0;

		virtual unsigned int getUsage() = 0;
		virtual unsigned int getSizeInBytes() = 0;
		virtual unsigned int getDataType() = 0;
	};
}