#include "config/EngineConfig.h"
#include "game/Engine.h"

Engine::Engine(const EngineConfig &cfg)
    : config(cfg),
      window(cfg.window),
      renderer(cfg.render, window),
      shader(cfg.shader)
{
    shader.addVertexShader();
    shader.addFragmentShader();
    shader.linkProgram();
    shader.use();
}

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
