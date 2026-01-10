#pragma once

#include "core/entities/EntityBuilder.h"
#include "game/WorldBuilder.h"
#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include "core/Window.h"

class Engine
{
  private:
    EngineConfig config;
    Window window;
    Renderer renderer;
    WorldBuilder worldBuilder;
    EntityBuilder entityBuilder;

  public:
    Engine(const EngineConfig &config);

    // @brief Main Loop
    void run();
};
