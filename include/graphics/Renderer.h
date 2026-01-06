#pragma once

#include "config/EngineConfig.h"
#include "game/Mesh.h"
#include "graphics/Shader.h"
#include "core/Dtos.h"
#include <glm/mat4x4.hpp>

class Renderer
{
  private:
    RenderConfig config;

  public:
    Renderer(const RenderConfig &config);

    // @brief set clear color & clear
    void clear() const;

    // @brief changes binded Vertex Array and Shader
    void draw(
        const Mesh &mesh,
        const Shader &shader,
        SpaceMatrices &matrices);
};
