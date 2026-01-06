#include "graphics/FrameClock.h"
#include <GLFW/glfw3.h>

float FrameClock::lastFrame = 0.0f;
float FrameClock::deltaTime = 0.0f;

void FrameClock::updateDeltaTime()
{
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

float FrameClock::getDeltaTime()
{
    return deltaTime;
}
