#pragma once
#include <glm/vec4.hpp>


struct ShaderConfig
{
    const char *vertexShaderPath = "assets/shaders/vertexShader.glsl";
    const char *fragmentShaderPath = "assets/shaders/fragmentShader.glsl";
};

struct WindowConfig
{
    int width = 1280;
    int height = 720;
    const char *title = "FPS Shooter";
    bool vsync = true;
};

struct RenderConfig
{
    glm::vec4 clearColor{0.5f, 1.0f, 1.2f, 1.0f};
    bool enableDepthTest = true;
};

struct EngineConfig
{
    WindowConfig window;
    RenderConfig render;
};
