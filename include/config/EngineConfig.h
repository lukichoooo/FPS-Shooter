#pragma once

#include "config/Colors.h"
#include <cstddef>
#include <glm/ext/vector_float3.hpp>
#include <glm/vec4.hpp>


// static


class MeshFactoryConfig
{
  public:
    static constexpr size_t meshesSize = 16;
};

class SceneConfig
{
  public:
    static constexpr size_t staticEntitiesSize = 16;
    static constexpr size_t dynamicEntitiesSize = 16;
};

// other


class EntityConfigStruct
{
  public:
    glm::vec3 pos{0.0f, 0.0f, 0.0f};
    glm::vec3 rotation{0.0f, 0.0f, 0.0f};
    glm::vec3 scale{1.0f, 1.0f, 1.0f};
    glm::vec4 color{Colors::Default};


    EntityConfigStruct operator+(const EntityConfigStruct &o) const
    {
        return {
            this->pos + o.pos,
            this->rotation + o.rotation,
            this->scale * o.scale,
            this->color != Colors::Default ? this->color : o.color,
        };
    }

    EntityConfigStruct operator+(const glm::vec4 &color) const
    {
        return {
            this->pos,
            this->rotation,
            this->scale,
            this->color != Colors::Default ? this->color : color,
        };
    }
};

class CharacterConfig : public EntityConfigStruct
{
  public:
    float height{1.8f};
    float jumpStrength{1.0f};
    float walkSpeed{3.0f};

    float runSpeedMultiplier{3.5f};
};

struct PlayerConfig
{
    float speedFovMultiplier{1.4f};
    CharacterConfig characterConfig;
};


// stuff


struct InputConfig
{
    // @brief can cause weird spinning arund
    float sensitivity{0.58f};
    bool invertY{true};
};

struct CameraConfig
{
    float defaultFOV{70.0f};
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
    glm::vec4 clearColor{Colors::SkyBlue};
    bool enableDepthTest{true};
};


// big


struct EngineConfig
{
    PlayerConfig player;
    InputConfig input;
    CameraConfig camera;
    WindowConfig window;
    RenderConfig render;
    ShaderConfig shader;
};
