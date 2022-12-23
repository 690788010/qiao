#include "context.h"

using namespace qiao;

Context::Context() {
	_clearColor = Color::BLACK();
	_clearDepth = 1.0;
	_clearStencil = 0;

	// Sync GL state with default render state.
	syncRenderState(_renderState);
};

Context::~Context() {

};

void Context::clear(ClearState& clearState) {
	// apply clearColor
	Color color = clearState.getColor();
	if (!color.equals(_clearColor)) {
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
	ScissorTest scissorTest = clearState.getScissorTest();
	ScissorTest _scissorTest = _renderState.getScissorTest();
	if (scissorTest.getWidth() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Width must be greater than or equal to zero!");
	}
	if (scissorTest.getHeight() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Height must be greater than or equal to zero!");
	}
	if (scissorTest.getEnabled() != _scissorTest.getEnabled()) {
		enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
		_scissorTest.setEnabled(scissorTest.getEnabled());
	}
	if (scissorTest.getEnabled()) {
		if (scissorTest.getX() != _scissorTest.getX() ||
			scissorTest.getY() != _scissorTest.getY() ||
			scissorTest.getWidth() != _scissorTest.getWidth() ||
			scissorTest.getHeight() != _scissorTest.getHeight()) {
			glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());
			_scissorTest.setX(scissorTest.getX());
			_scissorTest.setY(scissorTest.getY());
			_scissorTest.setWidth(scissorTest.getWidth());
			_scissorTest.setHeight(scissorTest.getHeight());
		}
	}

	// apply ColorMask
	ColorMask colorMask = clearState.getColorMask();
	ColorMask _colorMask = _renderState.getColorMask();
	if (!colorMask.equals(_colorMask)) {
		glColorMask(colorMask.getRed(), colorMask.getGreen(), colorMask.getBlue(), colorMask.getAlpha());
		_renderState.setColorMask(colorMask);
	}

	// apply DepthMask
	if (clearState.getDepthMask() != _renderState.getDepthTest().getDepthMask()) {
		glDepthMask(clearState.getDepthMask());
		_renderState.getDepthTest().setDepthMask(clearState.getDepthMask());
	}
};

void Context::draw(GLenum primitiveType, DrawState* drawState, SceneState* sceneState) {
	verifyDraw(drawState, sceneState);
	applyBeforeDraw(drawState, sceneState);

	VertexArray* vertexArray = drawState->getVertexArray();
	IndexBuffer* indexBuffer = vertexArray->getIndexBuffer();

	if (indexBuffer != nullptr) {
		glDrawElements(primitiveType, indexBuffer->getCount(), indexBuffer->getType(), 0);
	}
	else {

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

void Context::syncRenderState(RenderState& renderState) {
	PrimitiveRestart primitiveRestart = renderState.getPrimitiveRestart();
	enable(GL_PRIMITIVE_RESTART, primitiveRestart.getEnabled());
	glPrimitiveRestartIndex(primitiveRestart.getIndex());

	CullFace cullFace = renderState.getCullFace();
	enable(GL_CULL_FACE, cullFace.getEnabled());
	glFrontFace(cullFace.getFrontFaceMode());
	glCullFace(cullFace.getCullFaceMode());

	enable(GL_PROGRAM_POINT_SIZE, renderState.getProgramPointSize());

	glPolygonMode(GL_FRONT_AND_BACK, renderState.getPolygonMode());

	ScissorTest scissorTest = renderState.getScissorTest();
	enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
	glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());

	DepthTest depthTest = renderState.getDepthTest();
	enable(GL_DEPTH_TEST, true);
	glDepthFunc(depthTest.getDepthFunc());
	glDepthMask(depthTest.getDepthMask());
	glDepthRange(depthTest.getNear(), depthTest.getFar());

	Blending blending = renderState.getBlending();
	enable(GL_BLEND, blending.getEnabled());
	glBlendFuncSeparate(blending.getSrcRGB(), blending.getDstRGB(), blending.getSrcAlpha(), blending.getDstAlpha());
	glBlendEquationSeparate(blending.getRgbEquation(), blending.getAlphaEquation());
};

void Context::enable(GLenum cap, bool enabled) {
	if (enabled) {
		glEnable(cap);
	}
	else {
		glDisable(cap);
	}
};

void Context::verifyDraw(DrawState* drawState, SceneState* sceneState) {
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

void Context::applyBeforeDraw(DrawState* drawState, SceneState* sceneState) {
	applyRenderState(drawState->getRenderState());
	applyVertexArray(drawState->getVertexArray());
	applyShaderProgram(drawState, sceneState);
};

void Context::applyRenderState(RenderState& renderState) {
	// apply PrimitiveRestart
	PrimitiveRestart primitiveRestart = renderState.getPrimitiveRestart();
	PrimitiveRestart _primitiveRestart = _renderState.getPrimitiveRestart();
	if (primitiveRestart.getEnabled() != _primitiveRestart.getEnabled()) {
		enable(GL_PRIMITIVE_RESTART, primitiveRestart.getEnabled());
		_primitiveRestart.setEnabled(primitiveRestart.getEnabled());
	}

	// apply CullFace
	CullFace cullFace = renderState.getCullFace();
	CullFace _cullFace = _renderState.getCullFace();
	if (cullFace.getEnabled() != _cullFace.getEnabled()) {
		enable(GL_CULL_FACE, cullFace.getEnabled());
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

	// apply ProgramPointSize
	if (renderState.getProgramPointSize() != _renderState.getProgramPointSize()) {
		enable(GL_PROGRAM_POINT_SIZE, renderState.getProgramPointSize());
		_renderState.setProgramPointSize(renderState.getProgramPointSize());
	}

	// apply PolygonMode
	if (renderState.getPolygonMode() != _renderState.getPolygonMode()) {
		glPolygonMode(GL_FRONT_AND_BACK, renderState.getPolygonMode());
		_renderState.setPolygonMode(renderState.getPolygonMode());
	}

	// apply ScissorTest
	ScissorTest scissorTest = renderState.getScissorTest();
	ScissorTest _scissorTest = _renderState.getScissorTest();
	if (scissorTest.getWidth() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Width must be greater than or equal to zero!");
	}
	if (scissorTest.getHeight() < 0) {
		throw std::invalid_argument("renderState.ScissorTest.Height must be greater than or equal to zero!");
	}
	if (scissorTest.getEnabled() != _scissorTest.getEnabled()) {
		enable(GL_SCISSOR_TEST, scissorTest.getEnabled());
		_scissorTest.setEnabled(scissorTest.getEnabled());
	}
	if (scissorTest.getEnabled()) {
		if (scissorTest.getX() != _scissorTest.getX() ||
			scissorTest.getY() != _scissorTest.getY() ||
			scissorTest.getWidth() != _scissorTest.getWidth() ||
			scissorTest.getHeight() != _scissorTest.getHeight()) {
			glScissor(scissorTest.getX(), scissorTest.getY(), scissorTest.getWidth(), scissorTest.getHeight());
			_scissorTest.setX(scissorTest.getX());
			_scissorTest.setY(scissorTest.getY());
			_scissorTest.setWidth(scissorTest.getWidth());
			_scissorTest.setHeight(scissorTest.getHeight());
		}
	}

	// apply StencilTest
	StencilTest stencilTest = renderState.getStencilTest();
	StencilTest _stencilTest = _renderState.getStencilTest();
	if (stencilTest.getEnabled() != _stencilTest.getEnabled()) {
		enable(GL_STENCIL_TEST, stencilTest.getEnabled());
		_stencilTest.setEnabled(stencilTest.getEnabled());
	}

	// apply DepthTest
	DepthTest depthTest = renderState.getDepthTest();
	DepthTest _depthTest = _renderState.getDepthTest();
	if (depthTest.getEnabled() != _depthTest.getEnabled()) {
		enable(GL_DEPTH_TEST, depthTest.getEnabled());
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
				throw std::invalid_argument("renderState.DepthRange.Near must be between zero and one.");
			}
			if (depthTest.getFar() < 0.0 || depthTest.getFar() > 1.0) {
				throw std::invalid_argument("renderState.DepthRange.Far must be between zero and one.");
			}
			glDepthRange(depthTest.getNear(), depthTest.getFar());
			_depthTest.setNear(depthTest.getNear());
			_depthTest.setFar(depthTest.getFar());
		}
	}

	// apply Blending
	Blending blending = renderState.getBlending();
	Blending _blending = _renderState.getBlending();
	if (blending.getEnabled() != _blending.getEnabled()) {
		enable(GL_BLEND, blending.getEnabled());
		_blending.setEnabled(blending.getEnabled());
	}
	if (blending.getEnabled()) {
		if ((blending.getSrcRGB() != _blending.getSrcRGB()) ||
			(blending.getDstRGB() != _blending.getDstRGB()) ||
			(blending.getSrcAlpha() != _blending.getSrcAlpha()) ||
			(blending.getDstAlpha() != _blending.getDstAlpha())) {
			glBlendFuncSeparate(blending.getSrcRGB(), blending.getDstRGB(), blending.getSrcAlpha(), blending.getDstAlpha());
		}
		if ((blending.getRgbEquation() != _blending.getRgbEquation()) ||
			(blending.getAlphaEquation() != _blending.getAlphaEquation())) {
			glBlendEquationSeparate(blending.getRgbEquation(), blending.getAlphaEquation());
		}
	}

	// apply ColorMask
	ColorMask colorMask = renderState.getColorMask();
	ColorMask _colorMask = _renderState.getColorMask();
	if (!colorMask.equals(_colorMask)) {
		glColorMask(colorMask.getRed(), colorMask.getGreen(), colorMask.getBlue(), colorMask.getAlpha());
		_renderState.setColorMask(colorMask);
	}
};

void Context::applyVertexArray(VertexArray* vertexArray) {
	vertexArray->bind();
	vertexArray->clean();
};

void Context::applyShaderProgram(DrawState* drawState, SceneState* sceneState) {
	ShaderProgram* shaderProgram = drawState->getShaderProgram();
	if (shaderProgram != _boundShaderProgram) {
		shaderProgram->use();
		_boundShaderProgram = shaderProgram;
	}
	_boundShaderProgram->clean(this, drawState, sceneState);
};