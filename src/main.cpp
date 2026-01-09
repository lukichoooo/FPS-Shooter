#include "config/jsons/ConfigService.h"
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

    ConfigService configService;
    // configService.saveDefaults();
    EngineConfig config = configService.load();

    Engine engine(config);

    engine.run();


    glfwTerminate();
    return 0;
}
