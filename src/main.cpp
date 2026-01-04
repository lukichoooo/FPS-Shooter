#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <core/Window.h>
#include "config/EngineConfig.h"
#include "game/Engine.h"

int main()
{
    EngineConfig config;
    Engine engine(config);

    engine.run();

    return 0;
}
