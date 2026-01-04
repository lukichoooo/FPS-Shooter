#pragma once
#include "config/EngineConfig.h"
#include "core/Window.h"

class Renderer
{
  public:
    Renderer(const RenderConfig &config, Window &window);

    // @brief set clear colour & clear
    void clear();

  private:
    RenderConfig renderConfig;
    Window &window;
};
