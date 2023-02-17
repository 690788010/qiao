/**
 * @file blending.cc
 * @brief
 * @author yangqiao
 * @date December 2022
 */

#include "blending.h"

using namespace qiao;

Blending::Blending() : _enabled{ false }, _srcRGB{ GL_ONE }, _dstRGB{ GL_ZERO }, 
    _srcAlpha{ GL_ONE }, _dstAlpha{ GL_ZERO }, _rgbEquation{ GL_FUNC_ADD }, _alphaEquation{ GL_FUNC_ADD }{};

bool Blending::getEnabled() {
    return _enabled;
};

void Blending::setEnabled(bool enabled) {
    _enabled = enabled;
};

GLenum Blending::getSrcRGB() {
    return _srcRGB;
};

void Blending::setSrcRGB(GLenum srcRGB) {
    _srcRGB = srcRGB;
};

GLenum Blending::getDstRGB() {
    return _dstRGB;
};

void Blending::setDstRGB(GLenum dstRGB) {
    _dstRGB = dstRGB;
};

GLenum Blending::getSrcAlpha() {
    return _srcAlpha;
};

void Blending::setSrcAlpha(GLenum srcAlpha) {
    _srcAlpha = srcAlpha;
};

GLenum Blending::getDstAlpha() {
    return _dstAlpha;
};

void Blending::setDstAlpha(GLenum dstAlpha) {
    _dstAlpha = dstAlpha;
};

GLenum Blending::getRgbEquation() {
    return _rgbEquation;
};

void Blending::setRgbEquation(GLenum rgbEquation) {
    _rgbEquation = rgbEquation;
};

GLenum Blending::getAlphaEquation() {
    return _alphaEquation;
};

void Blending::setAlphaEquation(GLenum alphaEquation) {
    _alphaEquation = alphaEquation;
};

