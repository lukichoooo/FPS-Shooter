#pragma once

#include "core/entities/DynamicEntity.h"
#include "game/animation/FlyingTargetAnimator.h"

class PyramidTarget : DynamicEntity
{
    FlyingTargetAnimator animator;

    void drop();
};
