#pragma once

#include "config/EngineConfig.h"
#include "spdlog/spdlog.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <spdlog/spdlog.h>

namespace glm
{
inline void to_json(nlohmann::json &j, const glm::vec3 &v) { j = {v.x, v.y, v.z}; }
inline void from_json(const nlohmann::json &j, glm::vec3 &v)
{
    auto arr = j.get<std::vector<float>>();
    v = glm::vec3(arr[0], arr[1], arr[2]);
}

inline void to_json(nlohmann::json &j, const glm::vec4 &v) { j = {v.r, v.g, v.b, v.a}; }
inline void from_json(const nlohmann::json &j, glm::vec4 &v)
{
    auto arr = j.get<std::vector<float>>();
    v = glm::vec4(arr[0], arr[1], arr[2], arr[3]);
}
} // namespace glm

using json = nlohmann::json;

// ------------------- Helpers for glm -------------------
inline void to_json(json &j, const glm::vec3 &v) { j = {v.x, v.y, v.z}; }
inline void from_json(const json &j, glm::vec3 &v)
{
    auto arr = j.get<std::vector<float>>();
    v = glm::vec3(arr[0], arr[1], arr[2]);
}

inline void to_json(json &j, const glm::vec4 &v) { j = {v.r, v.g, v.b, v.a}; }
inline void from_json(const json &j, glm::vec4 &v)
{
    auto arr = j.get<std::vector<float>>();
    v = glm::vec4(arr[0], arr[1], arr[2], arr[3]);
}

// ------------------- Config Structs -------------------

// InputConfig
inline void to_json(json &j, const InputConfig &c)
{
    j = {
        {"sensitivity", c.sensitivity},
        {"invertY", c.invertY},
    };
}
inline void from_json(const json &j, InputConfig &c)
{
    j.at("sensitivity").get_to(c.sensitivity);
    j.at("invertY").get_to(c.invertY);
}

// ShaderConfig
inline void to_json(json &j, const ShaderConfig &c)
{
    j = {
        {"vertexShaderPath", c.vertexShaderPath},
        {"fragmentShaderPath", c.fragmentShaderPath},
    };
}
inline void from_json(const json &j, ShaderConfig &c)
{
    j.at("vertexShaderPath").get_to(c.vertexShaderPath);
    j.at("fragmentShaderPath").get_to(c.fragmentShaderPath);
}

// RenderConfig
inline void to_json(json &j, const RenderConfig &c)
{
    j = {
        {"clearColor", c.clearColor},
        {"enableDepthTest", c.enableDepthTest},
    };
}
inline void from_json(const json &j, RenderConfig &c)
{
    j.at("clearColor").get_to(c.clearColor);
    j.at("enableDepthTest").get_to(c.enableDepthTest);
}


// CameraAnimatorConfig
inline void to_json(json &j, const CameraAnimatorConfig &c)
{
    j = {
        {"speedFovMultiplier", c.speedFovMultiplier},
    };
}
inline void from_json(const json &j, CameraAnimatorConfig &c)
{
    j.at("speedFovMultiplier").get_to(c.speedFovMultiplier);
}

// CameraConfig
inline void to_json(json &j, const CameraConfig &c)
{
    j = {
        {"animatorConfig", c.animatorConfig},
        {"defaultFOV", c.defaultFOV},
        {"nearPlane", c.nearPlane},
        {"farPlane", c.farPlane},
        {"front", c.front},
        {"up", c.up},
    };
}
inline void from_json(const json &j, CameraConfig &c)
{
    j.at("defaultFOV").get_to(c.defaultFOV);
    j.at("nearPlane").get_to(c.nearPlane);
    j.at("farPlane").get_to(c.farPlane);
    j.at("front").get_to(c.front);
    j.at("up").get_to(c.up);
}

// WindowConfig
inline void to_json(json &j, const WindowConfig &c) { j = {{"width", c.width}, {"height", c.height}, {"title", c.title}, {"vsync", c.vsync}}; }
inline void from_json(const json &j, WindowConfig &c)
{
    j.at("width").get_to(c.width);
    j.at("height").get_to(c.height);
    j.at("title").get_to(c.title);
    j.at("vsync").get_to(c.vsync);
}

// CharacterAnimatorConfig
inline void to_json(json &j, const CharacterAnimatorConfig &c)
{
    j = {
        {"groundY", c.groundY},
        {"gravity", c.gravity},
        {"jumpVelocity", c.jumpVelocity},
        {"jumpAccelerationTime", c.jumpAccelerationTime},
        {"walkSpeed", c.walkSpeed},
        {"runSpeed", c.runSpeed},
        {"accelerationTime", c.accelerationTime},
        {"decelerationTime", c.decelerationTime},
    };
}
inline void from_json(const json &j, CharacterAnimatorConfig &c)
{
    j.at("groundY").get_to(c.groundY);
    j.at("gravity").get_to(c.gravity);
    j.at("jumpVelocity").get_to(c.jumpVelocity);
    j.at("jumpAccelerationTime").get_to(c.jumpAccelerationTime);
    j.at("walkSpeed").get_to(c.walkSpeed);
    j.at("runSpeed").get_to(c.runSpeed);
    j.at("accelerationTime").get_to(c.accelerationTime);
    j.at("decelerationTime").get_to(c.decelerationTime);
}


// CharacterConfig
inline void to_json(json &j, const CharacterConfig &c)
{
    j = {
        {"height", c.height},
        {"animatorConfig", c.animatorConfig},
        {"pos", c.pos},
        {"rotation", c.rotation},
        {"scale", c.scale},
        {"color", c.color},
    };
}
inline void from_json(const json &j, CharacterConfig &c)
{
    j.at("height").get_to(c.height);
    j.at("animatorConfig").get_to(c.animatorConfig);
    j.at("pos").get_to(c.pos);
    j.at("rotation").get_to(c.rotation);
    j.at("scale").get_to(c.scale);
    j.at("color").get_to(c.color);
}

// PlayerConfig
inline void to_json(json &j, const PlayerConfig &c)
{
    j = {
        {"characterConfig", c.characterConfig},
    };
}
inline void from_json(const json &j, PlayerConfig &c)
{
    j.at("characterConfig").get_to(c.characterConfig);
}

// JSON serialization
inline void to_json(nlohmann::json &j, const FlyingTargetAnimatorConfig &c)
{
    j = {
        {"gravity", c.gravity},
        {"groundY", c.groundY},
        {"flySpeed", c.flySpeed},
        {"boostSpeed", c.boostSpeed},
        {"accelerationTime", c.accelerationTime},
        {"decelerationTime", c.decelerationTime},
        {"orbitRadius", c.orbitRadius},
        {"orbitCenter", c.orbitCenter},
        {"orbitSpeed", c.orbitSpeed},
        {"spinSpeed", c.spinSpeed}};
}

inline void from_json(const nlohmann::json &j, FlyingTargetAnimatorConfig &c)
{
    j.at("gravity").get_to(c.gravity);
    j.at("groundY").get_to(c.groundY);
    j.at("flySpeed").get_to(c.flySpeed);
    j.at("boostSpeed").get_to(c.boostSpeed);
    j.at("accelerationTime").get_to(c.accelerationTime);
    j.at("decelerationTime").get_to(c.decelerationTime);
    j.at("orbitRadius").get_to(c.orbitRadius);
    j.at("orbitCenter").get_to(c.orbitCenter);
    j.at("orbitSpeed").get_to(c.orbitSpeed);
    j.at("spinSpeed").get_to(c.spinSpeed);
}


// EntityCOnfigStruct
inline void to_json(json &j, const EntityConfigStruct &c)
{
    j = {
        {"pos", c.pos},
        {"rotation", c.rotation},
        {"scale", c.scale},
        {"color", c.color},
    };
}

inline void from_json(const json &j, EntityConfigStruct &c)
{
    j.at("pos").get_to(c.pos);
    j.at("rotation").get_to(c.rotation);
    j.at("scale").get_to(c.scale);
    j.at("color").get_to(c.color);
}

// FlyingTargetConfig
inline void to_json(json &j, const FlyingTargetConfig &c)
{
    j = {
        {"animatorConfig", c.animatorConfig},
    };
}
inline void from_json(const json &j, FlyingTargetConfig &c)
{
    j.at("animatorConfig").get_to(c.animatorConfig);
}

// WorldBuilderConfig
inline void to_json(json &j, const WorldBuilderConfig &c)
{
    j = {
        {"character", c.character},
        {"flyingTarget", c.flyingTarget},
        {"entity", c.entity},
    };
}
inline void from_json(const json &j, WorldBuilderConfig &c)
{
    j.at("character").get_to(c.character);
    j.at("flyingTarget").get_to(c.flyingTarget);
    j.at("entity").get_to(c.entity);
}

// EngineConfig
inline void to_json(json &j, const EngineConfig &c)
{
    j = {
        {"player", c.player},
        {"input", c.input},
        {"camera", c.camera},
        {"window", c.window},
        {"render", c.render},
        {"shader", c.shader},
        {"worldBuilder", c.worldBuilder}};
}

inline void from_json(const json &j, EngineConfig &c)
{
    j.at("player").get_to(c.player);
    j.at("input").get_to(c.input);
    j.at("camera").get_to(c.camera);
    j.at("window").get_to(c.window);
    j.at("render").get_to(c.render);
    j.at("shader").get_to(c.shader);
    j.at("worldBuilder").get_to(c.worldBuilder);
}


// ------------------- ConfigService -------------------
class ConfigService
{
    const std::string path = "assets/config/EngineConfigs.json";
    EngineConfig config;
    bool configLoaded{false};

  public:
    ConfigService() = default;

    EngineConfig load()
    {
        EngineConfig fileConfig;
        try
        {
            std::ifstream file(path);
            file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            nlohmann::json j;
            file >> j;

            j.get_to(fileConfig);
            spdlog::info("[ConfigService] Successfully loaded config from: {}", path);
        }
        catch (const std::exception &e)
        {
            spdlog::error("[ConfigService] Failed to load config: {}", e.what());
            std::abort();
        }
        return fileConfig;
    }


    void saveDefaults() const
    {
        try
        {
            std::ofstream file(path);
            if (!file.is_open())
            {
                spdlog::error("[ConfigService] file not open at: {}", path);
                std::abort();
            }

            nlohmann::json j = config;
            file << j.dump(4);
        }
        catch (const std::exception &e)
        {
            spdlog::error("[ConfigService] Failed to save config: ", e.what());
            std::abort();
        }
    }

    const EngineConfig &getStored() const
    {
        if (!configLoaded)
        {
            spdlog::error("[ConfigService] configureaton not loaded");
            std::abort();
        }
        return config;
    }
};
