#pragma once

#include "graphics/Shader.h"
#include "config/EngineConfig.h"
#include "core/Window.h"
#include "graphics/Renderer.h"

class Engine
{
  public:
    Engine(const EngineConfig &config);

    // @brief Main Loop
    void run();

  private:
    EngineConfig config;
    Window window;
    Renderer renderer;
    Shader shader;
};
