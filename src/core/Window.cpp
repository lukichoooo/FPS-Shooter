#include <GL/glew.h>
#include "core/Window.h"
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


Window::Window(const WindowConfig &config)
{
    if (!glfwInit())
    {
        spdlog::error("Failed to initialize GLFW");
        glfwTerminate();
        std::abort();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(config.width, config.height, config.title, NULL, NULL);
    if (!window)
    {
        spdlog::error("Failed to create GLFW window: {}x{}", config.width, config.height);
        glfwTerminate();
        std::abort();
    }

    glfwMakeContextCurrent(window);

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

void Window::makeContextCurrent()
{
    glfwMakeContextCurrent(window);
}

void Window::getFramebufferSize(int &width, int &height) const
{
    width = bufferWidth;
    height = bufferHeight;
}
