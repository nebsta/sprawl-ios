//
//  Renderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Renderer.hpp"

typedef std::vector<Renderer*>::iterator RendererIterator;

Renderer::Renderer() : Renderer(RENDERER_DEFAULT_COLOR) {
    
}

Renderer::Renderer(const glm::vec4& tint) : Renderer(RENDERER_DEFAULT_SHAPE, tint) {
    
}

Renderer::Renderer(const Mesh& mesh, const glm::vec4& tint) : Renderer(mesh, tint, RENDERER_DEFAULT_SHADER) {
    
}

Renderer::Renderer(const Mesh& mesh, const glm::vec4& tint, const std::string& shader) :
_mesh(mesh),
_tint(tint),
_modelviewMatrix(glm::mat4()),
_projectionMatrix(RENDERER_DEFAULT_PROJECTION),
_shader(shader),
_clipChildren(true) {
    
}

Renderer::~Renderer() {
}

void Renderer::render() {
    preDraw();
    draw();
    onPostDraw();
}

#pragma mark Clipping

void Renderer::pushClippingRect() {
    if (!_clipChildren) {
        return;
    }
    
    // save a copy of the current clipping plan and applying our own clipping
    glGetIntegerv(GL_SCISSOR_BOX, _parentScissorRect);
    glScissor(_clippingRect.x, _clippingRect.y, _clippingRect.z, _clippingRect.w);
}

void Renderer::popClippingRect() {
    if (!_clipChildren) {
        return;
    }
    
    glScissor(_parentScissorRect[0], _parentScissorRect[1], _parentScissorRect[2], _parentScissorRect[3]);
}

#pragma mark Setters

void Renderer::setModelviewMatrix(const glm::mat4& matrix) {
    _modelviewMatrix = matrix;
}

void Renderer::setProjectionMatrix(const glm::mat4& matrix) {
    _projectionMatrix = matrix;
}

void Renderer::setTint(const glm::vec4& tint) {
    _tint = tint;
}

void Renderer::setClippingRect(const glm::vec4& clippingRect) {
    _clippingRect = clippingRect;
}

void Renderer::setClipChildren(const bool& clipChildren) {
    _clipChildren = clipChildren;
}

#pragma mark Virtual Methods

void Renderer::preDraw() {
    
}

void Renderer::draw() {
    
}

void Renderer::onPostDraw() {
    
}
