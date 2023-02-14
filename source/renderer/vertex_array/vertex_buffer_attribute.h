/*****************************************************************//**
 * \file   vertex_buffer_attribute.h
 * \brief  
 * 
 * \author yangqiao
 * \date   December 2022
 *********************************************************************/

#pragma once

#include "../buffers/vertex_buffer.h"

namespace qiao {
	/**
	 * VertexBufferAttribute类是VAO的单个顶点属性配置.
	 */
	class VertexBufferAttribute {
	public:
		/**
		 * 构造函数.
		 * 
		 * \param vertexBuffer	顶点缓冲
		 * \param size	每个分量的组成数量
		 * \param type	分量的数据类型
		 * \param normalized	// 是否归一化	
		 * \param stride	// 间隔
		 * \param _offset	// 偏移
		 */
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