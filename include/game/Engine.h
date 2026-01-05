#pragma once

#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include "core/Window.h"

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
};
