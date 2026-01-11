#include "game/entities/Gun.h"
#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"
#include "spdlog/spdlog.h"


Gun::Gun(const GunConfig &config, Mesh *mesh)
    : DynamicEntity(config, mesh),
      config(config) {}


void Gun::shoot()
{
    if (bullets == 0)
    {
        spdlog::info("mag empty, must reload!");
        this->reload();
    }
    spdlog::info("pew...");
    bullets--;
}

void Gun::reload()
{
    spdlog::info("gun reloading");
    bullets = config.magazineSize;
}
