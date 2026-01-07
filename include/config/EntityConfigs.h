#pragma once

#include "config/EngineConfig.h"

struct EntityConfigs
{
    // ---------- BASE ----------
    inline static const EntityConfigStruct Default{
        .initialPos = {0.0f, 0.0f, 0.0f},
        .initialRotation = {0.0f, 0.0f, 0.0f},
        .initialScale = {1.0f, 1.0f, 1.0f},
    };

    // ---------- GROUND ----------
    inline static const EntityConfigStruct Ground{
        .initialPos = {0.0f, 0.0f, 0.0f},
        .initialRotation = {0.0f, 0.0f, 0.0f},
        .initialScale = {50.0f, 1.0f, 50.0f},
    };

    // ---------- SCALE PRESETS ----------
    inline static const EntityConfigStruct Small{
        .initialScale = {0.5f, 0.5f, 0.5f},
    };

    inline static const EntityConfigStruct Smaller{
        .initialScale = {0.25f, 0.25f, 0.25f},
    };

    inline static const EntityConfigStruct Big{
        .initialScale = {2.0f, 2.0f, 2.0f},
    };

    inline static const EntityConfigStruct Bigger{
        .initialScale = {5.0f, 5.0f, 5.0f},
    };

    // ---------- ROTATION PRESETS (degrees) ----------
    inline static const EntityConfigStruct RotateLeft{
        .initialRotation = {0.0f, -90.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateRight{
        .initialRotation = {0.0f, 90.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateUp{
        .initialRotation = {-90.0f, 0.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateDown{
        .initialRotation = {90.0f, 0.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateBack{
        .initialRotation = {0.0f, 180.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateFront{
        .initialRotation = {0.0f, 0.0f, 0.0f},
    };
};
