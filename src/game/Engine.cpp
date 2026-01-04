
// Engine.cpp
#include "config/EngineConfig.h"
#include "game/Engine.h"

Engine::Engine(const EngineConfig &cfg)
    : config(cfg), window(cfg.window), renderer(cfg.render, window) {}

void Engine::run()
{
    while (!glfwWindowShouldClose(window.getHandle()))
    {
        renderer.clear();

        // Game update & render calls go here

        glfwSwapBuffers(window.getHandle());
        glfwPollEvents();
    }
}
