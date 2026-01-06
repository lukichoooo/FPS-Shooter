#include "game/Scene.h"
#include "game/Entity.h"

Scene::Scene(std::span<Entity *> entities)
    : entities(entities) {}
