#include "game/entities/Gun.h"
#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"
#include "spdlog/spdlog.h"


Gun::Gun(const GunConfig &config, Mesh *mesh)
    : DynamicEntity(config, mesh),
      config(config) {}

void Gun::shoot()
{
    spdlog::info("EVERYONE GET DOWN, HE HAS A GUN");
}
