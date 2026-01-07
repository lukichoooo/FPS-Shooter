#pragma once

#include <GLFW/glfw3.h>
#include "config/EngineConfig.h"

class Window
{
  private:
    GLFWwindow *window{nullptr};


  public:
    Window(const WindowConfig &config);
    ~Window();

    void getFrameBufferSize(int &width, int &height) const;

    GLFWwindow *getHandle() const { return window; }

    void makeContextCurrent() { glfwMakeContextCurrent(window); }
    void swapBuffers() { glfwSwapBuffers(window); }
    void pollEvents() { glfwPollEvents(); }
    void destroyWindow() { glfwDestroyWindow(window); }
    bool windowShouldClose() { return glfwWindowShouldClose(window); }
};
