#pragma once

#include "../../vertex_array/vertex_buffer_attribute.h"

namespace qiao {
	class VertexBufferAttributeGL3x : public qiao::VertexBufferAttribute {
	public:
		VertexBufferAttributeGL3x(VertexBuffer* vertexBuffer, unsigned int numOfComponent, unsigned int componentDataType,
			bool normalized, unsigned int _strideInBytes, unsigned int _offsetInBytes);
		~VertexBufferAttributeGL3x();

		virtual VertexBuffer* getVertexBuffer();
		virtual unsigned int getNumOfComponent();
		virtual unsigned int getComponentDataType();
		virtual bool getNormalized();
		virtual unsigned int getStrideInBytes();
		virtual unsigned int getOffsetInBytes();
		virtual bool getDirty();
		virtual void setDirty(bool val);

	private:
		VertexBuffer* _vertexBuffer;
		unsigned int _numOfComponent;
		unsigned int _componentDataType;
		bool _normalized;
		unsigned int _strideInBytes;
		unsigned int _offsetInBytes;
		bool _dirty;
	};
}