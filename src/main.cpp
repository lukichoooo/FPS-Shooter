#include "game/Engine.h"
#include "spdlog/spdlog.h"

int main()
{
    if (!glfwInit())
    {
        spdlog::error("Failed to initialize GLFW");
        glfwTerminate();
        std::abort();
    }

    EngineConfig config;
    Engine engine(config);

    engine.run();

    glfwTerminate();
    return 0;
}
