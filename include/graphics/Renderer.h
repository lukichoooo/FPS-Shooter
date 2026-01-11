#pragma once

#include "config/EngineConfig.h"
#include "core/scene/Scene.h"
#include "game/player/Player.h"
#include <glm/mat4x4.hpp>

class Renderer
{
  private:
    RenderConfig config;

  public:
    Renderer(const RenderConfig &config);

    // @brief set clear color & clear
    void beginFrame() const;

    // @brief changes binded Vertex Array and Shader
    void submit(Scene &scene, Shader &shader);
    void submit(Player &player, Shader &shader);
};
