#pragma once

#include "config/EngineConfig.h"
#include "game/Scene.h"
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
};
