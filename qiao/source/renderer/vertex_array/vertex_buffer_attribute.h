#pragma once

#include "../buffers/vertex_buffer.h"

namespace qiao {
	class VertexBufferAttribute {
	public:
		virtual VertexBuffer* getVertexBuffer() = 0;
		virtual unsigned int getNumOfComponent() = 0;
		virtual unsigned int getComponentDataType() = 0;
		virtual bool getNormalized() = 0;
		virtual unsigned int getStrideInBytes() = 0;
		virtual unsigned int getOffsetInBytes() = 0;
		virtual bool getDirty() = 0;
		virtual void setDirty(bool val) = 0;
		virtual bool operator==(VertexBufferAttribute* attribute) = 0;
	};
}