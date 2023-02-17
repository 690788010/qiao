/**
 * @file context.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "context.h"

using namespace qiao;

Context::Context() {
	_clearColor = Color::BLACK;
	_clearDepth = 1.0;
	_clearStencil = 0;

	// Sync GL state with default render state.
	_renderState = new RenderState();
	_syncRenderState(_renderState);
};

Context::~Context() {
	if (_renderState != nullptr) {
		delete _renderState;
		_renderState = nullptr;
	}
};

void Context::draw(GLenum primitiveType, DrawState* drawState, SceneState* sceneState) {
	_verifyDraw(drawState, sceneState);
	_applyBeforeDraw(drawState, sceneState);

	VertexArray* vertexArray = drawState->getVertexArray();
	IndexBuffer* indexBuffer = vertexArray->getIndexBuffer();

	if (indexBuffer != nullptr) {
		glDrawElements(primitiveType, indexBuffer->getCount(), indexBuffer->getType(), 0);
	}
	else {

	}
};

void Context::clear(ClearState& clearState) {
	// apply clearColor
	Color color = clearState.getColor();
	if (color != _clearColor) {
		glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
		_clearColor = color;
	}

	// apply clearDepth
	if (clearState.getDepth() != _clearDepth) {
		glClearDepth(clearState.getDepth());
		_clearDepth = clearState.getDepth();
	}

	// apply clearStencil
	if (clearState.getStencil() != _clearStencil) {
		glClearStencil(clearState.getStencil());
		_clearStencil = clearState.getStencil();
	}

	// 清除缓存
	glClear(clearState.getClearMask());

	// apply ScissorTest
	_applyScissorTest(clearState.getScissorTest());

	// apply ColorMask
	_applyColorMask(clearState.getColorMask());

	// apply DepthMask
	if (clearState.getDepthMask() != _renderState->getDepthTest().getDepthMask()) {
		glDepthMask(clearState.getDepthMask());
		_renderState->getDepthTest().setDepthMask(clearState.getDepthMask());
	}
};


VertexArray* Context::createVertexArray(Mesh& mesh, ShaderVertexAttributeCollection shaderAttributes, GLenum usage) {
	VertexArray* vertexArray = new VertexArray();

	// 为VertexArray设置对应的IndexBuffer
	IndicesBase* meshIndices = mesh.getIndices();
	if (meshIndices != nullptr) {
		if (meshIndices->getType() == GL_UNSIGNED_SHORT) {
			IndicesUnsignedShort* indicesUnsignedShort = (IndicesUnsignedShort*)meshIndices;
			size_t size = meshIndices->getSize();
			unsigned short* indices = new unsigned short[size];
			for (size_t i = 0; i < size; i++) {
				indices[i] = indicesUnsignedShort->getIndex(i);
			}
			IndexBuffer* indexBuffer = new IndexBuffer(usage, sizeof(unsigned short) * size);
			indexBuffer->copyFromSystemMemory(indices, GL_UNSIGNED_SHORT, 0, sizeof(unsigned short) * size);
			vertexArray->setIndexBuffer(indexBuffer);
		}
		else if (meshIndices->getType() == GL_UNSIGNED_INT) {
			IndicesUnsignedInt* indicesUnsignedInt = (IndicesUnsignedInt*)meshIndices;
			size_t size = meshIndices->getSize();
			unsigned int* indices = new unsigned int[size];
			for (size_t i = 0; i < size; i++) {
				indices[i] = indicesUnsignedInt->getIndex(i);
			}
			IndexBuffer* indexBuffer = new IndexBuffer(usage, sizeof(unsigned int) * size);
			indexBuffer->copyFromSystemMemory(indices, GL_UNSIGNED_INT, 0, sizeof(unsigned int) * size);
			vertexArray->setIndexBuffer(indexBuffer);
		}
		else {
			throw std::invalid_argument("mesh.Indices.type is not supported!");
		}
	}

	// 为VertexArray设置对应的VertexBufferAttributes
	VertexAttributeCollection attributes = mesh.getAttributes();
	for (VertexAttribute* attribute : attributes) {
		// 如果在ShaderVertexAttributeCollection中找不到对应的ShaderVertexAttribute则抛出异常
		if (shaderAttributes.find(attribute->getName()) == shaderAttributes.end()) {
			std::string msg = "VertexAttribute " + attribute->getName();
			msg += " is not present in ShaderVertexAttributeCollection!";
			throw std::invalid_argument(msg);
		}
		
		// 如果VertexAttribute数据类型和ShaderVertexAttribute数据类型不相同则抛出异常
		ShaderVertexAttribute* shaderAttribute = shaderAttributes[attribute->getName()];
		if (attribute->getType() != shaderAttribute->getType()) {
			std::string msg = "The type of VertexAttribute " + attribute->getName();
			msg += " is not equal to the type of ShaderVertexAttribute ";
			msg += shaderAttribute->getName();
			throw std::invalid_argument(msg);
		}

		if (attribute->getType() == GL_FLOAT) {
			VertexAttributeFloat* attributeFloat = (VertexAttributeFloat*)attribute;
			// 将数据存为一维数组
			size_t idx = 0;
			float* valuesArr = new float[attributeFloat->getValues().size()];
			for (float value : attributeFloat->getValues()) {
				valuesArr[idx++] = value;
			}
			// 创建VertexBuffer并将数据存入显存缓冲区
			VertexBuffer* vertexBuffer = new VertexBuffer(usage, sizeof(valuesArr));
			vertexBuffer->copyFromSystemMemory(valuesArr, 0, sizeof(valuesArr));

			VertexBufferAttribute* bufferAttribute = new VertexBufferAttribute(vertexBuffer, 1, GL_FLOAT, GL_FALSE, 0, 0);
			vertexArray->getAttributes().setByIndex(shaderAttribute->getLocation(), bufferAttribute);
		}
		else if (attribute->getType() == GL_FLOAT_VEC4) {
			VertexAttributeVector4F* attributeVector4F = (VertexAttributeVector4F*)attribute;
			// 将数据存为一维数组
			size_t len = attributeVector4F->getValues().size() * 4;
			float* valuesArr = new float[len];
			size_t idx = 0;
			for (Vector4F* vector4F : attributeVector4F->getValues()) {
				valuesArr[idx++] = vector4F->getX();
				valuesArr[idx++] = vector4F->getY();
				valuesArr[idx++] = vector4F->getZ();
				valuesArr[idx++] = vector4F->getW();
			}
			// 创建VertexBuffer并将数据存入显存缓冲区
			VertexBuffer* vertexBuffer = new VertexBuffer(usage, sizeof(float) * len);
			vertexBuffer->copyFromSystemMemory(valuesArr, 0, sizeof(float) * len);
			// 将顶点属性指针的配置保存到VAO
			VertexBufferAttribute* bufferAttribute = new VertexBufferAttribute(vertexBuffer, 4, GL_FLOAT, GL_FALSE, 0, 0);
			vertexArray->getAttributes().setByIndex(shaderAttribute->getLocation(), bufferAttribute);
		}

	}

	return vertexArray;
};

//Texture2D* Context::createTexture2D(std::string imgPath, GLenum target, GLint internalformat, GLenum format, 
//	GLenum type, bool generateMipmaps) 
//{
//	// 获取图片的绝对路径
//	char* cwd;
//	cwd = _getcwd(NULL, 0);
//	std::string path = cwd;
//	path += imgPath;
//
//	// 加载图片数据到内存
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
//	if (!data) {
//		throw std::invalid_argument("Failed to load texture");
//	}
//
//	// 将内存中的图片数据拷贝到显存
//	unsigned int size = width * height * nrChannels;
//	WritePixelBuffer* write_pixel_buffer = new WritePixelBuffer(GL_STATIC_DRAW, size);
//	write_pixel_buffer->copyFromSystemMemory(data, 0, size);
//
//	Texture2D* texture = new Texture2D(target, internalformat, width, height, format, type, generateMipmaps);
//
//	return texture;
//};

void Context::_syncRenderState(RenderState* renderState) {
	PrimitiveRestart primitiveRestart = renderState->getPrimitiveRestart();
	_enable(GL_PRIMITIVE_RESTART, primitiveRestart.getEnabled());
	glPrimitiveRestartIndex(primitiveRestart.getIndex());

	CullFace cullFace = renderState->getCullFace();
	_enable(GL_CULL_FACE, cullFace.getEnabled());
	glFrontFace(cullFace.getFrontFaceMode());
	glCullFace(cullFace.getCullFaceMode());

	_enable(GL_PROGRAM_POINT_SIZE, renderState->getProgramPointSize());

	glPolygonMode(GL_FRONT_AND_BACK, renderState->getPolygonMode());

	ScissorTest scissorTest = renderState->getScissorTest();
	_enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
	glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());

	DepthTest depthTest = renderState->getDepthTest();
	_enable(GL_DEPTH_TEST, true);
	glDepthFunc(depthTest.getDepthFunc());
	glDepthMask(depthTest.getDepthMask());
	glDepthRange(depthTest.getNear(), depthTest.getFar());

	Blending blending = renderState->getBlending();
	_enable(GL_BLEND, blending.getEnabled());
	glBlendFuncSeparate(blending.getSrcRGB(), blending.getDstRGB(), blending.getSrcAlpha(), blending.getDstAlpha());
	glBlendEquationSeparate(blending.getRgbEquation(), blending.getAlphaEquation());
};

void Context::_enable(GLenum cap, bool enabled) {
	if (enabled) {
		glEnable(cap);
	}
	else {
		glDisable(cap);
	}
};

void Context::_verifyDraw(DrawState* drawState, SceneState* sceneState) {
	if (drawState == nullptr) {
		throw std::invalid_argument("argument drawState is null!");
	}

	if (drawState->getShaderProgram() == nullptr) {
		throw std::invalid_argument("drawState.shaderProgram is null!");
	}

	if (drawState->getVertexArray() == nullptr) {
		throw std::invalid_argument("drawState.vertexArray is null!");
	}

	if (sceneState == nullptr) {
		throw std::invalid_argument("sceneState is null!");
	}
};

void Context::_applyBeforeDraw(DrawState* drawState, SceneState* sceneState) {
	_applyRenderState(drawState->getRenderState());
	_applyVertexArray(drawState->getVertexArray());
	_applyShaderProgram(drawState, sceneState);
};

void Context::_applyRenderState(RenderState* renderState) {
	// apply PrimitiveRestart
	_applyPrimitiveRestart(renderState->getPrimitiveRestart());

	// apply CullFace
	_applyCullFace(renderState->getCullFace());

	// apply ProgramPointSize
	_applyProgramPointSize(renderState->getProgramPointSize());

	// apply PolygonMode
	_applyPolygonMode(renderState->getPolygonMode());

	// apply ScissorTest
	_applyScissorTest(renderState->getScissorTest());

	// apply StencilTest
	_applyStencilTest(renderState->getStencilTest());

	// apply DepthTest
	_applyDepthTest(renderState->getDepthTest());

	// apply Blending
	_applyBlending(renderState->getBlending());

	// apply ColorMask
	_applyColorMask(renderState->getColorMask());
};

void Context::_applyVertexArray(VertexArray* vertexArray) {
	vertexArray->bind();
	vertexArray->clean();
};

void Context::_applyShaderProgram(DrawState* drawState, SceneState* sceneState) {
	ShaderProgram* shaderProgram = drawState->getShaderProgram();
	if (shaderProgram != _boundShaderProgram) {
		shaderProgram->use();
		_boundShaderProgram = shaderProgram;
	}
	_boundShaderProgram->clean(this, drawState, sceneState);
};

void Context::_applyPrimitiveRestart(PrimitiveRestart& primitiveRestart) {
	PrimitiveRestart _primitiveRestart = _renderState->getPrimitiveRestart();
	if (primitiveRestart.getEnabled() != _primitiveRestart.getEnabled()) {
		_enable(GL_PRIMITIVE_RESTART, primitiveRestart.getEnabled());
		_primitiveRestart.setEnabled(primitiveRestart.getEnabled());
	}
	if (primitiveRestart.getEnabled()) {
		if (primitiveRestart.getIndex() != _primitiveRestart.getIndex()) {
			glPrimitiveRestartIndex(primitiveRestart.getIndex());
			_primitiveRestart.setIndex(primitiveRestart.getIndex());
		}
	}
};

void Context::_applyCullFace(CullFace& cullFace) {
	CullFace _cullFace = _renderState->getCullFace();
	if (cullFace.getEnabled() != _cullFace.getEnabled()) {
		_enable(GL_CULL_FACE, cullFace.getEnabled());
		_cullFace.setEnabled(cullFace.getEnabled());
	}
	if (cullFace.getEnabled()) {
		if (cullFace.getCullFaceMode() != _cullFace.getCullFaceMode()) {
			glCullFace(cullFace.getCullFaceMode());
			_cullFace.setCullFaceMode(cullFace.getCullFaceMode());
		}
		if (cullFace.getFrontFaceMode() != _cullFace.getFrontFaceMode()) {
			glFrontFace(cullFace.getFrontFaceMode());
			_cullFace.setFrontFaceMode(cullFace.getFrontFaceMode());
		}
	}
};

void Context::_applyProgramPointSize(GLboolean programPointSize) {
	if (programPointSize != _renderState->getProgramPointSize()) {
		_enable(GL_PROGRAM_POINT_SIZE, programPointSize);
		_renderState->setProgramPointSize(programPointSize);
	}
};

void Context::_applyPolygonMode(GLenum polygonMode) {
	if (polygonMode != _renderState->getPolygonMode()) {
		glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
		_renderState->setPolygonMode(polygonMode);
	}
};

void Context::_applyScissorTest(ScissorTest& scissorTest) {
	ScissorTest _scissorTest = _renderState->getScissorTest();
	if (scissorTest.getEnabled() != _scissorTest.getEnabled()) {
		_enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
		_scissorTest.setEnabled(scissorTest.getEnabled());
	}
	if (scissorTest.getEnabled()) {
		if (scissorTest.getX() != _scissorTest.getX() ||
			scissorTest.getY() != _scissorTest.getY() ||
			scissorTest.getWidth() != _scissorTest.getWidth() ||
			scissorTest.getHeight() != _scissorTest.getHeight()) 
		{
			glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());
			_scissorTest.setX(scissorTest.getX());
			_scissorTest.setY(scissorTest.getY());
			_scissorTest.setWidth(scissorTest.getWidth());
			_scissorTest.setHeight(scissorTest.getHeight());
		}
	}
};

void Context::_applyStencilTest(StencilTest& stencilTest) {
	StencilTest _stencilTest = _renderState->getStencilTest();
	if (stencilTest.getEnabled() != _stencilTest.getEnabled()) {
		_enable(GL_STENCIL_TEST, stencilTest.getEnabled());
		_stencilTest.setEnabled(stencilTest.getEnabled());
	}
};

void Context::_applyDepthTest(DepthTest& depthTest) {
	DepthTest _depthTest = _renderState->getDepthTest();
	if (depthTest.getEnabled() != _depthTest.getEnabled()) {
		_enable(GL_DEPTH_TEST, depthTest.getEnabled());
		_depthTest.setEnabled(depthTest.getEnabled());
	}
	if (depthTest.getEnabled()) {
		if (depthTest.getDepthFunc() != _depthTest.getDepthFunc()) {
			glDepthFunc(depthTest.getDepthFunc());
			_depthTest.setDepthFunc(depthTest.getDepthFunc());
		}
		if (depthTest.getDepthMask() != _depthTest.getDepthMask()) {
			glDepthMask(depthTest.getDepthMask());
			_depthTest.setDepthMask(depthTest.getDepthMask());
		}
		if (depthTest.getNear() != _depthTest.getNear() || depthTest.getFar() != _depthTest.getFar()) {
			if (depthTest.getNear() < 0.0 || depthTest.getNear() > 1.0) {
				throw std::invalid_argument("renderState->DepthRange.Near must be between zero and one.");
			}
			if (depthTest.getFar() < 0.0 || depthTest.getFar() > 1.0) {
				throw std::invalid_argument("renderState->DepthRange.Far must be between zero and one.");
			}
			glDepthRange(depthTest.getNear(), depthTest.getFar());
			_depthTest.setNear(depthTest.getNear());
			_depthTest.setFar(depthTest.getFar());
		}
	}
};

void Context::_applyBlending(Blending& blending) {
	Blending _blending = _renderState->getBlending();
	if (blending.getEnabled() != _blending.getEnabled()) {
		_enable(GL_BLEND, blending.getEnabled());
		_blending.setEnabled(blending.getEnabled());
	}
	if (blending.getEnabled()) {
		if ((blending.getSrcRGB() != _blending.getSrcRGB()) ||
			(blending.getDstRGB() != _blending.getDstRGB()) ||
			(blending.getSrcAlpha() != _blending.getSrcAlpha()) ||
			(blending.getDstAlpha() != _blending.getDstAlpha()))
		{
			glBlendFuncSeparate(blending.getSrcRGB(), blending.getDstRGB(), blending.getSrcAlpha(), blending.getDstAlpha());
			_blending.setSrcRGB(blending.getSrcRGB());
			_blending.setDstRGB(blending.getDstRGB());
			_blending.setSrcAlpha(blending.getSrcAlpha());
			_blending.setDstAlpha(blending.getDstAlpha());
		}
		if ((blending.getRgbEquation() != _blending.getRgbEquation()) ||
			(blending.getAlphaEquation() != _blending.getAlphaEquation()))
		{
			glBlendEquationSeparate(blending.getRgbEquation(), blending.getAlphaEquation());
			_blending.setRgbEquation(blending.getRgbEquation());
			_blending.setAlphaEquation(blending.getAlphaEquation());
		}
	}
};

void Context::_applyColorMask(ColorMask& colorMask) {
	ColorMask _colorMask = _renderState->getColorMask();
	if (colorMask != _colorMask) {
		glColorMask(colorMask.getRed(), colorMask.getGreen(), colorMask.getBlue(), colorMask.getAlpha());
		_renderState->setColorMask(colorMask);
	}
};
