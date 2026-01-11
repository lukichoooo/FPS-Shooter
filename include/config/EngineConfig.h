#pragma once

#include "config/Colors.h"
#include <cstddef>
#include <glm/ext/vector_float3.hpp>
#include <glm/vec4.hpp>
#include <string>


// static


struct MeshFactoryStorageConfig
{
    static constexpr size_t meshesSize = 16;
};

struct PlayerInventoryConfig
{
    static const int slots{3};
};

struct SceneStorageConfig
{
    static constexpr size_t staticEntitiesSize = 16;
    static constexpr size_t dynamicEntitiesSize = 16;
    static constexpr size_t pyramidTargetsSize = 16;
};

// other

struct EntityConfigStruct
{
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

    constexpr EntityConfigStruct operator*(int multiplier) const
    {
        return {
            pos * float(multiplier),
            rotation * float(multiplier),
            scale * float(multiplier),
            color,
        };
    }
};

struct FlyingTargetAnimatorConfig
{
    float gravity{9.81f};
    float groundY{0.0f};

    float flySpeed{6.5f};
    float boostSpeed{10.0f};
    float accelerationTime{0.00001f};
    float decelerationTime{0.000005f};

    float orbitRadius{0.5f};
    float orbitSpeed{5.0f};

    float rotationSpeed{6.0f};
    // glm::vec3 up{0.0f, 1.0f, 0.0f};
};


struct CharacterAnimatorConfig
{
    // Vertical Movement
    float groundY{0.0f};
    float gravity{9.81f};
    float jumpVelocity{5.0f};
    float jumpAccelerationTime{0.2f};

    // Horizontal Movement
    float walkSpeed{3.0f};
    float runSpeed{6.0f};
    float accelerationTime{0.00003f};
    float decelerationTime{0.00002f};
};


struct CharacterConfig : public EntityConfigStruct
{
    CharacterAnimatorConfig animatorConfig;
    float height{1.8f};
};

struct GunConfig : public EntityConfigStruct
{
    int magazineSize{3};


    GunConfig operator+(const EntityConfigStruct &o)
    {
        this->pos += o.pos;
        this->rotation += o.rotation;
        this->scale *= o.scale;
        if (this->color == Colors::Default)
            this->color = o.color;
        return *this;
    }

    // + operator with color
    GunConfig operator+(const glm::vec4 &color)
    {
        if (this->color == Colors::Default)
            this->color = color;
        return *this;
    }

    void operator=(const EntityConfigStruct &o)
    {
        this->EntityConfigStruct::operator=(o);
    }
};

struct PlayerConfig
{
    CharacterConfig character;
};

struct FlyingTargetConfig : public EntityConfigStruct
{
    FlyingTargetAnimatorConfig animatorConfig;

    FlyingTargetConfig() = default;
    FlyingTargetConfig(const EntityConfigStruct &base, FlyingTargetAnimatorConfig anim)
        : EntityConfigStruct(base), animatorConfig(anim) {}

    FlyingTargetConfig operator+(const EntityConfigStruct &o) const
    {
        FlyingTargetConfig result(*this);
        result.pos += o.pos;
        result.rotation += o.rotation;
        result.scale *= o.scale;
        if (result.color == Colors::Default)
            result.color = o.color;
        return result;
    }

    // + operator with color
    FlyingTargetConfig operator+(const glm::vec4 &color) const
    {
        FlyingTargetConfig result(*this);
        if (result.color == Colors::Default)
            result.color = color;
        return result;
    }

    void operator=(const EntityConfigStruct &o)
    {
        this->EntityConfigStruct::operator=(o);
    }
};


// stuff


struct InputConfig
{
    // @brief can cause weird spinning arund
    float sensitivity{0.58f};
    bool invertY{true};
};

struct CameraAnimatorConfig
{
    float speedFovMultiplier{1.4f};
};

struct CameraConfig
{
    CameraAnimatorConfig animatorConfig;
    float defaultFOV{70.0f};
    float nearPlane{0.1f};
    float farPlane{100.0f};
    glm::vec3 front{0.0f, 0.0f, -1.0f};
    glm::vec3 up{0.0f, 1.0f, 0.0f};
};

struct ShaderConfig
{
    std::string vertexShaderPath{"assets/shaders/vertexShader.glsl"};
    std::string fragmentShaderPath{"assets/shaders/fragmentShader.glsl"};
};

struct WindowConfig
{
    int width{1280};
    int height{720};
    std::string title{"FPS Shooter"};
    bool vsync{true};
};

struct RenderConfig
{
    glm::vec4 clearColor{Colors::SkyBlue};
    bool enableDepthTest{true};
};

struct WorldBuilderConfig
{
    CharacterConfig character;
    FlyingTargetConfig flyingTarget;
    EntityConfigStruct entity;
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
    WorldBuilderConfig worldBuilder;
};
