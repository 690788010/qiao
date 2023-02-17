/**
 * @file context.h
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#pragma once

#include <stdexcept>
#include <direct.h>

#include "./state/clear_state/clear_state.h"
#include "./state/draw_state/draw_state.h"
#include "scene/scene_state.h"
#include "../core/geometry/mesh.h"
#include "./vertex_array/vertex_array.h"
#include "./state/render_state/render_state.h"
#include "../core/geometry/indices/indices_unsigned_short.h"
#include "../core/geometry/indices/indices_unsigned_int.h"
#include "../core/geometry/vertex_attributes/vertex_attribute_float.h"
#include "../core/geometry/vertex_attributes/vertex_attribute_vector4f.h"
#include "textures/texture2d.h"
#include "buffers/write_pixel_buffer.h"

//#define STB_IMAGE_IMPLEMENTATION
//#include "../../third_party/stb_image/stb_image.h"


namespace qiao {
	/**
	 * @brief �������࣬��Ҫ���ڿ��ƴ��ڻ�������Ⱦ�����
	 */
	class Context {
	public:
		/**
		 * @brief Ĭ�Ϲ��캯��
		 */
		Context();
		~Context();

		/**
		 * @brief ���ƺ�����ÿ����һ�Σ����Ƶ�ǰ��һ֡
		 * 
		 * @param primitiveType ָ�����Ƶ�ͼԪ���͡��ɴ������³�����GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, 
		 * GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
		 * @param drawState DrawState�����ָ��
		 * @param sceneState SceneState�����ָ��
		 * 
		 * @return void
		 */
		void draw(GLenum primitiveType, DrawState* drawState, SceneState* sceneState);

		/**
		 * @brief �������������������ݣ��ָ�ΪĬ��״̬
		 * 
		 * @param clearState ClearState���������
		 * 
		 * @return void
		 */
		void clear(ClearState& clearState);

		/**
		 * @brief Ϊ�ض�Mesh���ɶ�Ӧ��VertexArray����
		 * 
		 * @param mesh Mesh���������
		 * @param shaderAttributes ShaderVertexAttributeCollection����
		 * @param usage ���ݵ�����ģʽ��������������Ϊ���³�����GL_STREAM_DRAW, GL_STREAM_READ, GL_STREAM_COPY, 
		 * GL_STATIC_DRAW, GL_STATIC_READ, GL_STATIC_COPY, GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, GL_DYNAMIC_COPY.
		 * 
		 * @return VertexArray�����ָ�� 
		 */
		VertexArray* createVertexArray(Mesh& mesh, ShaderVertexAttributeCollection shaderAttributes, GLenum usage);

		/**
		 * @brief Ϊ�ض�ͼƬ���ɶ�Ӧ��Texture2D����
		 * 
		 * @param imgPath ͼƬ��·��
		 * @param target ����Ŀ�ꡣ��ѡ������GL_TEXTURE_2D, GL_PROXY_TEXTURE_2D, GL_TEXTURE_1D_ARRAY, 
		 * GL_PROXY_TEXTURE_1D_ARRAY, GL_TEXTURE_RECTANGLE, GL_PROXY_TEXTURE_RECTANGLE, GL_TEXTURE_CUBE_MAP_POSITIVE_X, 
		 * GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 
		 * GL_TEXTURE_CUBE_MAP_POSITIVE_Z, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, GL_PROXY_TEXTURE_CUBE_MAP.
		 * @param internalformat �������ɫ�ɷֵ���������飺https://registry.khronos.org/OpenGL-Refpages/gl4/
		 * @param format �������ݵĸ�ʽ����ѡ������GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, GL_BGRA, GL_RED_INTEGER, 
		 * GL_RG_INTEGER, GL_RGB_INTEGER, GL_BGR_INTEGER, GL_RGBA_INTEGER, GL_BGRA_INTEGER, GL_STENCIL_INDEX, 
		 * GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL.
		 * @param type �������ݵ��������͡���ѡ������GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, 
		 * GL_INT, GL_HALF_FLOAT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5, 
		 * GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, 
		 * GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, 
		 * GL_UNSIGNED_INT_2_10_10_10_REV.
		 * @param generateMipmaps �Ƿ񴴽�Mipmap
		 * 
		 * @return Texture2D�����ָ��
		 */
		Texture2D* createTexture2D(std::string imgPath, GLenum target, GLint internalformat, GLenum format, 
			GLenum type, bool generateMipmaps);

	private:
		// Sync GL state with default render state.
		void _syncRenderState(RenderState* renderState);

		// enable or disable server-side GL capabilities
		void _enable(GLenum cap, bool enabled);

		// verify arguments
		void _verifyDraw(DrawState* drawState, SceneState* sceneState);

		void _applyBeforeDraw(DrawState* drawState, SceneState* sceneState);

		void _applyRenderState(RenderState* renderState);

		void _applyVertexArray(VertexArray* vertexArray);

		void _applyShaderProgram(DrawState* drawState, SceneState* sceneState);

		// ͬ������OpenGL�ü��������״̬
		void _applyScissorTest(ScissorTest& scissorTest);

		// ͬ������OpenGLģ��������״̬
		void _applyStencilTest(StencilTest& stencilTest);

		// ͬ������OpenGL��Ȳ������״̬
		void _applyDepthTest(DepthTest& depthTest);

		// ͬ������OpenGL�����ص�״̬
		void _applyBlending(Blending& blending);

		// ͬ������OpenGL�Ƿ�����ɫ���������ɫ������д����
		void _applyColorMask(ColorMask& colorMask);

		Color _clearColor;
		double _clearDepth;
		int _clearStencil;
		RenderState* _renderState;
		// ʹ���ߴ�������ShaderProgram�����ָ�룬���಻������ո�ShaderProgram������ڴ棬
		// �����ø�ShaderProgram����Ĵ����߸�������ڴ档
		ShaderProgram* _boundShaderProgram;		
	};
}