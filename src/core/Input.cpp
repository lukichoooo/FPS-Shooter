#include "core/Input.h"
#include "config/EngineConfig.h"
#include "core/Dtos.h"
#include <GLFW/glfw3.h>

Input::Input(
    const InputConfig &config,
    GLFWwindow *window,
    const FrameClock &frameClock)
    : config(config),
      window(window),
      frameClock(frameClock) {}


void Input::use()
{
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(window, this);
    glfwSetCursorPosCallback(window, this->mouseCallbackStatic);
}


void Input::handleKeyboardInput(Player &player, Camera &camera)
{
    glm::vec3 moveDir{0.0f};

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveDir += camera.getFront();

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        moveDir -= camera.getFront();

    glm::vec3 right = glm::normalize(
        glm::cross(camera.getFront(), camera.getUp()));

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        moveDir += right;

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        moveDir -= right;

    if (glm::length(moveDir) > 0.0f)
        moveDir = glm::normalize(moveDir);

    float speed = player.getWalkSpeed();

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        speed *= config.runSpeedMultiplier;

    player.move(moveDir * speed * frameClock.deltaTime);

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Input::handleMouseInput(Camera &camera)
{
    mouseChange.X *= config.sensitivity;
    mouseChange.Y *= config.sensitivity;

    camera.setPitch(camera.getPitch() + mouseChange.Y);
    camera.setYaw(camera.getYaw() + mouseChange.X);

    if (camera.getPitch() > 89.0f)
        camera.setPitch(89.0f);
    if (camera.getPitch() < -89.0f)
        camera.setPitch(-89.0f);
}


// private helper


void Input::mouseCallbackStatic(GLFWwindow *window, double x, double y)
{
    Input *input = static_cast<Input *>(glfwGetWindowUserPointer(window));
    if (input)
        input->processMouseInput(x, y);
}

void Input::processMouseInput(double x, double y)
{
    mouseChange.X = float(x - lastMouse.X);
    mouseChange.Y = float(lastMouse.Y - y);

    lastMouse.X = x;
    lastMouse.Y = y;
}
