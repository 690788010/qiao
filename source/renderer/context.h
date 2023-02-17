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
	 * @brief 上下文类，主要用于控制窗口画布的渲染与清除
	 */
	class Context {
	public:
		/**
		 * @brief 默认构造函数
		 */
		Context();
		~Context();

		/**
		 * @brief 绘制函数，每调用一次，绘制当前的一帧
		 * 
		 * @param primitiveType 指定绘制的图元类型。可传入以下常量：GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, 
		 * GL_LINES, GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY, GL_PATCHES
		 * @param drawState DrawState对象的指针
		 * @param sceneState SceneState对象的指针
		 * 
		 * @return void
		 */
		void draw(GLenum primitiveType, DrawState* drawState, SceneState* sceneState);

		/**
		 * @brief 清除函数，清除画布内容，恢复为默认状态
		 * 
		 * @param clearState ClearState对象的引用
		 * 
		 * @return void
		 */
		void clear(ClearState& clearState);

		/**
		 * @brief 为特定Mesh生成对应的VertexArray对象
		 * 
		 * @param mesh Mesh对象的引用
		 * @param shaderAttributes ShaderVertexAttributeCollection对象
		 * @param usage 数据的用例模式。可以允许设置为以下常量：GL_STREAM_DRAW, GL_STREAM_READ, GL_STREAM_COPY, 
		 * GL_STATIC_DRAW, GL_STATIC_READ, GL_STATIC_COPY, GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, GL_DYNAMIC_COPY.
		 * 
		 * @return VertexArray对象的指针 
		 */
		VertexArray* createVertexArray(Mesh& mesh, ShaderVertexAttributeCollection shaderAttributes, GLenum usage);

		/**
		 * @brief 为特定图片生成对应的Texture2D对象
		 * 
		 * @param imgPath 图片的路径
		 * @param target 纹理目标。可选常量：GL_TEXTURE_2D, GL_PROXY_TEXTURE_2D, GL_TEXTURE_1D_ARRAY, 
		 * GL_PROXY_TEXTURE_1D_ARRAY, GL_TEXTURE_RECTANGLE, GL_PROXY_TEXTURE_RECTANGLE, GL_TEXTURE_CUBE_MAP_POSITIVE_X, 
		 * GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 
		 * GL_TEXTURE_CUBE_MAP_POSITIVE_Z, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, GL_PROXY_TEXTURE_CUBE_MAP.
		 * @param internalformat 纹理的颜色成分的数量。详查：https://registry.khronos.org/OpenGL-Refpages/gl4/
		 * @param format 像素数据的格式。可选常量：GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, GL_BGRA, GL_RED_INTEGER, 
		 * GL_RG_INTEGER, GL_RGB_INTEGER, GL_BGR_INTEGER, GL_RGBA_INTEGER, GL_BGRA_INTEGER, GL_STENCIL_INDEX, 
		 * GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL.
		 * @param type 像素数据的数据类型。可选常量：GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, 
		 * GL_INT, GL_HALF_FLOAT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5, 
		 * GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, 
		 * GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, 
		 * GL_UNSIGNED_INT_2_10_10_10_REV.
		 * @param generateMipmaps 是否创建Mipmap
		 * 
		 * @return Texture2D对象的指针
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

		// 同步设置OpenGL裁剪测试相关状态
		void _applyScissorTest(ScissorTest& scissorTest);

		// 同步设置OpenGL模板测试相关状态
		void _applyStencilTest(StencilTest& stencilTest);

		// 同步设置OpenGL深度测试相关状态
		void _applyDepthTest(DepthTest& depthTest);

		// 同步设置OpenGL混合相关的状态
		void _applyBlending(Blending& blending);

		// 同步设置OpenGL是否开启颜色缓冲各个颜色分量的写操作
		void _applyColorMask(ColorMask& colorMask);

		Color _clearColor;
		double _clearDepth;
		int _clearStencil;
		RenderState* _renderState;
		// 使用者传进来的ShaderProgram对象的指针，本类不负责回收该ShaderProgram对象的内存，
		// 而是让该ShaderProgram对象的创建者负责回收内存。
		ShaderProgram* _boundShaderProgram;		
	};
}