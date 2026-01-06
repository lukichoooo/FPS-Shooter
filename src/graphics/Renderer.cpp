#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include "game/Entity.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>


Renderer::Renderer(const RenderConfig &config)
    : config(config)
{
    glEnable(GL_DEPTH_TEST);
}

void Renderer::beginFrame() const
{
    glClearColor(
        config.clearColor.r,
        config.clearColor.g,
        config.clearColor.b,
        config.clearColor.a);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::submit(Entity &entity)
{
    entity.draw();
};
