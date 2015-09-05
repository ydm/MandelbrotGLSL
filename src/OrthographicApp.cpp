#include "OrthographicApp.hpp"
#include <AntTweakBar.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "glm/ext.hpp"
#include "MandelbrotDrawable.hpp"


// ========================
// OrthographicApp
// ========================

OrthographicApp::OrthographicApp()
: drawables_()
{
}


OrthographicApp::~OrthographicApp()
{
}


bool OrthographicApp::init()
{
    if (drawables_.init() == false) {
	return false;
    }
    drawables_.addDrawable(new MandelbrotDrawable());
    drawables_.setViewMatrix(glm::value_ptr(glm::mat4(1.0f)));
    return true;
}


void OrthographicApp::terminate()
{
    drawables_.terminate();
}


bool OrthographicApp::update(const float dt)
{
    return drawables_.update(dt);
}


// ========================
// Callbacks
// ========================

void OrthographicApp::onChar(const unsigned int codepoint)
{
}


void OrthographicApp::onCursorPosition(const double xpos, const double ypos)
{
}


void OrthographicApp::onKey(const int key, const int scancode, const int action, const int mods)
{
}


void OrthographicApp::onMouseButton(int button, int action, int mods)
{
}


void OrthographicApp::onResize(const int width, const int height)
{
    const glm::mat4& projection = glm::ortho(-0.5f, 0.5f, -0.5f, 0.5f);
    drawables_.setProjectionMatrix(glm::value_ptr(projection));
}


void OrthographicApp::onScroll(const double xoffset, const double yoffset)
{
}


// ========================
// Draw routine
// ========================

void OrthographicApp::draw()
{
    drawables_.draw();
}
