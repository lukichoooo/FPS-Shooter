#pragma once

#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"

class Gun : public DynamicEntity
{
  private:
    GunConfig config;

    int bullets;


  public:
    Gun() = default;
    Gun(const GunConfig &config, Mesh *mesh);

    // TODO
    void shoot();
    void reload();
};
