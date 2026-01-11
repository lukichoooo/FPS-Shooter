#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include "game/player/Player.h"
#include "game/entities/PyramidTarget.h"


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

void Renderer::submit(Player &player, Shader &shader)
{
    player.getCharacter()->draw(shader);
};

void Renderer::submit(Scene &scene, Shader &shader)
{
    for (auto &e : scene.getDynamicEntities())
        e.draw(shader);

    for (auto &e : scene.getStaticEntities())
        e.draw(shader);

    for (PyramidTarget &e : scene.getPyramidTargets())
        e.draw(shader);
};
