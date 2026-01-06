#pragma once

#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include "core/Window.h"

class Engine
{
  private:
    EngineConfig config;
    Window window;
    Renderer renderer;

  public:
    Engine(const EngineConfig &config);

    // @brief Main Loop
    void run();
};
