
#include "blending.h"

using namespace qiao;

Blending::Blending() {
    _enabled = false;
    _srcRGB = BlendingFactor::ONE;
    _dstRGB = BlendingFactor::ZERO;
    _srcAlpha = BlendingFactor::ONE;
    _dstAlpha = BlendingFactor::ZERO;
    _rgbEquation = BlendEquation::FUNC_ADD;
    _alphaEquation = BlendEquation::FUNC_ADD;
};

bool Blending::getEnabled() {
    return _enabled;
};

void Blending::setEnabled(bool val) {
    _enabled = val;
};

BlendingFactor Blending::getSrcRGB() {
    return _srcRGB;
};

void Blending::setSrcRGB(BlendingFactor val) {
    _srcRGB = val;
};

BlendingFactor Blending::getDstRGB() {
    return _dstRGB;
};

void Blending::setDstRGB(BlendingFactor val) {
    _dstRGB = val;
};

BlendingFactor Blending::getSrcAlpha() {
    return _srcAlpha;
};

void Blending::setSrcAlpha(BlendingFactor val) {
    _srcAlpha = val;
};

BlendingFactor Blending::getDstAlpha() {
    return _dstAlpha;
};

void Blending::setDstApha(BlendingFactor val) {
    _dstAlpha = val;
};

BlendEquation Blending::getRgbEquation() {
    return _rgbEquation;
};

void Blending::setRgbEquation(BlendEquation val) {
    _rgbEquation = val;
};

BlendEquation Blending::getAlphaEquation() {
    return _alphaEquation;
};

void Blending::setAlphaEquation(BlendEquation val) {
    _alphaEquation = val;
};

