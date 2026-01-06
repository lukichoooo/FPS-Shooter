#pragma once
#include <glm/ext/vector_float3.hpp>
#include <glm/vec4.hpp>

class Character
{
  public:
    glm::vec3 initialPos{0.0f, 0.0f, 0.0f};
    float height{2.0f};
    float jumpStrength{1.0f};
    float walkSpeed{5.0f};

    float runSpeedMultiplier{3.0f};
    float speedFovMultiplier{1.4f};
};

class PlayerConfig : public Character
{
  public:
};

struct InputConfig
{
    // @brief can cause weird spinning arund
    float sensitivity{0.58f};
    bool invertY{true};
};

struct CameraConfig
{
    float width{1280.0f};
    float height{720.0f};
    float defaultFOV{90.0f};
    float nearPlane{0.1f};
    float farPlane{100.0f};
    glm::vec3 front{0.0f, 0.0f, -1.0f};
    glm::vec3 up{0.0f, 1.0f, 0.0f};
};

struct ShaderConfig
{
    const char *vertexShaderPath{"assets/shaders/vertexShader.glsl"};
    const char *fragmentShaderPath{"assets/shaders/fragmentShader.glsl"};
};

struct WindowConfig
{
    int width{1280};
    int height{720};
    const char *title{"FPS Shooter"};
    bool vsync{true};
};

struct RenderConfig
{
    glm::vec4 clearColor{0.5f, 1.0f, 1.2f, 1.0f};
    bool enableDepthTest{true};
};

struct EngineConfig
{
    PlayerConfig player;
    InputConfig input;
    CameraConfig camera;
    WindowConfig window;
    RenderConfig render;
    ShaderConfig shader;
};
