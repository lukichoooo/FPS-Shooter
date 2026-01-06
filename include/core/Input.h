#pragma once

#include "config/EngineConfig.h"
#include "core/Camera.h"
#include "core/Dtos.h"
#include "game/Player.h"
#include <GLFW/glfw3.h>

class Input
{
  private:
    InputConfig config;

    GLFWwindow *window;
    MousePos lastMouse{0, 0};
    MousePos mouseChange{0, 0};

    bool keyPressed[GLFW_KEY_LAST + 1]{};


    static void mouseCallbackStatic(GLFWwindow *window, double x, double y);
    void processMouseSensorInput(double x, double y);

  public:
    Input(const InputConfig &config, GLFWwindow *window);

    // @brief changes player position
    void handleKeyInput(Player &player, const Camera &camera);

    // @brief changes camera orientation
    void handleMouseSensorInput(Camera &camera);

    void use();
};
