#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

class GLTestContext
{
  public:
    static void init()
    {
        static bool initialized = false;
        if (initialized)
            return;

        if (!glfwInit())
            std::abort();

        // Hidden window, 1x1
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        GLFWwindow *window = glfwCreateWindow(1, 1, "test", nullptr, nullptr);
        if (!window)
            std::abort();

        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK)
            std::abort();

        initialized = true;
    }

    static void shutdown()
    {
        glfwTerminate();
    }
};
