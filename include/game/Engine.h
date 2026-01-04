
// Engine.h
#pragma once
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
};
