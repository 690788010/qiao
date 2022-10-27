
#include "blending.h"

using namespace qiao;

Blending::Blending() {
    enabled = false;
    srcRGB = BlendingFactor::ONE;
    dstRGB = BlendingFactor::ZERO;
    srcAlpha = BlendingFactor::ONE;
    dstAlpha = BlendingFactor::ZERO;
    rgbEquation = BlendEquation::FUNC_ADD;
    alphaEquation = BlendEquation::FUNC_ADD;
};

bool Blending::getEnabled() {
    return enabled;
};

void Blending::setEnabled(bool val) {
    enabled = val;
};

BlendingFactor Blending::getSrcRGB() {
    return srcRGB;
};

void Blending::setSrcRGB(BlendingFactor val) {
    srcRGB = val;
};

BlendingFactor Blending::getDstRGB() {
    return dstRGB;
};

void Blending::setDstRGB(BlendingFactor val) {
    dstRGB = val;
};

BlendingFactor Blending::getSrcAlpha() {
    return srcAlpha;
};

void Blending::setSrcAlpha(BlendingFactor val) {
    srcAlpha = val;
};

BlendingFactor Blending::getDstAlpha() {
    return dstAlpha;
};

void Blending::setDstApha(BlendingFactor val) {
    dstAlpha = val;
};

BlendEquation Blending::getRgbEquation() {
    return rgbEquation;
};

void Blending::setRgbEquation(BlendEquation val) {
    rgbEquation = val;
};

BlendEquation Blending::getAlphaEquation() {
    return alphaEquation;
};

void Blending::setAlphaEquation(BlendEquation val) {
    alphaEquation = val;
};

