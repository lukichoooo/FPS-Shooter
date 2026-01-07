#pragma once

#include "core/MeshFactory.h"
#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include "core/Window.h"

class Engine
{
  private:
    EngineConfig config;
    Window window;
    Renderer renderer;
    MeshFactory meshBuilder;

  public:
    Engine(const EngineConfig &config);

    // @brief Main Loop
    void run();
};
