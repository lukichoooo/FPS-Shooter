#pragma once

#include "game/Mesh.h"
#include "config/EngineConfig.h"
#include "core/Window.h"
#include "graphics/Shader.h"
#include "core/Dtos.h"
#include <glm/mat4x4.hpp>

class Renderer
{
  public:
    Renderer(const RenderConfig &config, Window &window);

    // @brief set clear colour & clear
    void clear() const;

    // @brief changes binded Vertex Array and Shader
    void draw(
        const Mesh &mesh,
        const Shader &shader,
        const SpaceMatrices &matrices) const;

  private:
    RenderConfig renderConfig;
    Window &window;
};
