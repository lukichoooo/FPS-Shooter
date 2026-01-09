#include "core/Input.h"
#include "config/EngineConfig.h"
#include "core/Dtos.h"
#include <GLFW/glfw3.h>

Input::Input(
    const InputConfig &config, GLFWwindow *window)
    : config(config),
      window(window) {}


void Input::use()
{
    glfwSetWindowUserPointer(window, this);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, Input::mouseCallbackStatic);
}


void Input::handleKeyInput(Player &player, const Camera &camera)
{
    glm::vec3 moveDir{0.0f};
    glm::vec3 right = glm::normalize(
        glm::cross(camera.getFront(), camera.getUp()));

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveDir += camera.getFront();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        moveDir -= camera.getFront();
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        moveDir += right;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        moveDir -= right;

    if (glm::length(moveDir) > 0.0f)
        moveDir = glm::normalize(moveDir);

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        player.run(moveDir);
    else
        player.walk(moveDir);

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        player.jump();

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Input::handleMouseSensorInput(Camera &camera)
{
    mouseChange.X *= config.sensitivity;
    mouseChange.Y *= config.sensitivity;

    camera.setPitch(camera.getPitch() + (config.invertY ? mouseChange.Y : -mouseChange.Y));
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
        input->processMouseSensorInput(x, y);
}

void Input::processMouseSensorInput(double x, double y)
{
    mouseChange.X = x - lastMouse.X;
    mouseChange.Y = lastMouse.Y - y;

    lastMouse.X = x;
    lastMouse.Y = y;
}
