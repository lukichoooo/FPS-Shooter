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


void Input::mouseCallbackStatic(GLFWwindow *window, double x, double y)
{
    Input *input = static_cast<Input *>(glfwGetWindowUserPointer(window));
    if (input)
        input->processMouseSensorInput(x, y);
}

void Input::handleInput(Player &player, Camera &camera)
{
    handleKeyInput(player, camera);
    handleMouseSensorInput(camera);
}


// private helper


void Input::handleKeyInput(Player &player, const Camera &camera)
{
    handleDirectionalMovement(player, camera);
    handleItemKeys(player);
    handleMouseKeys(player);
    handleExitKeys();
}


void Input::processMouseSensorInput(double x, double y)
{
    mouseChange.X = x - lastMouse.X;
    mouseChange.Y = lastMouse.Y - y;

    lastMouse.X = x;
    lastMouse.Y = y;
}


void Input::handleMouseSensorInput(Camera &camera)
{
    mouseChange.X *= config.sensitivity;
    mouseChange.Y *= config.sensitivity;

    camera.setPitch(camera.getPitch() + (config.invertY ? mouseChange.Y : -mouseChange.Y));
    camera.setYaw(camera.getYaw() + mouseChange.X);

    float newPitch = camera.getPitch() + (config.invertY ? mouseChange.Y : -mouseChange.Y);
    newPitch = glm::clamp(newPitch, -89.0f, 89.0f);
    camera.setPitch(newPitch);
}


void Input::handleDirectionalMovement(Player &player, const Camera &camera)
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
}


void Input::handleItemKeys(Player &player)
{
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        player.selectPreviousItem();
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        player.selectNextItem();
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        player.reload();
}


void Input::handleMouseKeys(Player &player)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        player.shoot();
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        // TODO:
        // Right mouse button is pressed
    }
}

void Input::handleExitKeys()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
