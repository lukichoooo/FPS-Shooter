#pragma once
#include <GLFW/glfw3.h>
#include "config/EngineConfig.h"

class Window
{
  public:
    Window(const WindowConfig &config);
    ~Window();

    void makeContextCurrent();
    void getFramebufferSize(int &width, int &height) const;

    inline GLFWwindow *getHandle() const { return window; }

  private:
    GLFWwindow *window{nullptr};
    int bufferWidth{};
    int bufferHeight{};
};
