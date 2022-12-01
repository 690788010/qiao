#pragma once

#include "../buffers/vertex_buffer.h"

namespace qiao {
	class VertexBufferAttribute {
	public:
		VertexBufferAttribute(VertexBuffer* vertexBuffer, GLint size, GLenum type,
			GLboolean normalized, GLsizei stride, unsigned int _offset);
		~VertexBufferAttribute();

		VertexBuffer* getVertexBuffer();
		GLint getSize();
		GLenum getType();
		GLboolean getNormalized();
		GLsizei getStride();
		unsigned int getOffset();
		bool getEnabled();
		void setEnabled(bool val);

	private:
		VertexBuffer* _vertexBuffer;
		GLint _size;					// Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4.
		GLenum _type;				    // Specifies the data type of each component in the array.
		GLboolean _normalized;			// specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
		GLsizei _stride;				// Specifies the byte offset between consecutive generic vertex attributes.
		unsigned int _offset;			// Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target.
	};
}