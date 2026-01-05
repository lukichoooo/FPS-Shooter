#include "config/EngineConfig.h"
#include "core/Window.h"
#include "graphics/Renderer.h"

Renderer::Renderer(const RenderConfig &config, Window &window)
    : renderConfig(config),
      window(window) {}

void Renderer::clear()
{
    glClearColor(
        renderConfig.clearColor.r,
        renderConfig.clearColor.g,
        renderConfig.clearColor.b,
        renderConfig.clearColor.a);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
