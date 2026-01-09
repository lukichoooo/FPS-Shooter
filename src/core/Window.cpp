#include <GL/glew.h>
#include "core/Window.h"
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


Window::Window(const WindowConfig &config)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(config.width, config.height, config.title.c_str(), NULL, NULL);
    if (!window)
    {
        spdlog::error("Failed to create GLFW window: {}x{}", config.width, config.height);
        glfwTerminate();
        std::abort();
    }

    glfwMakeContextCurrent(window);

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

    if (glewInit() != GLEW_OK)
    {
        spdlog::error("Failed to initialize GLEW");
        glfwDestroyWindow(window);
        glfwTerminate();
        std::abort();
    }

    glViewport(0, 0, bufferWidth, bufferHeight);

    if (config.vsync)
        glfwSwapInterval(1);
}

Window::~Window()
{
    if (window)
        glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::getFrameBufferSize(int &width, int &height) const
{
    glfwGetFramebufferSize(window, &width, &height);
}
