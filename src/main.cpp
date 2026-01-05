#include "game/Engine.h"

int main()
{
    EngineConfig config;
    Engine engine(config);

    engine.run();

    return 0;
}
