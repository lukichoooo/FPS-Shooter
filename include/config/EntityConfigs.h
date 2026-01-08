#pragma once

#include "config/EngineConfig.h"

struct EntityConfigs
{
    // ---------- BASE ----------
    inline static const EntityConfigStruct Default{
        .pos = {0.0f, 0.0f, 0.0f},
        .rotation = {0.0f, 0.0f, 0.0f},
        .scale = {1.0f, 1.0f, 1.0f},
        .color = Colors::Default,
    };

    // ---------- GROUND ----------
    inline static const EntityConfigStruct Ground{
        .pos = {0.0f, 0.0f, 0.0f},
        .rotation = {0.0f, 0.0f, 0.0f},
        .scale = {50.0f, 1.0f, 50.0f},
        .color = Colors::Default,
    };

    // ---------- SCALE PRESETS ----------
    inline static const EntityConfigStruct Small{
        .scale = {0.5f, 0.5f, 0.5f},
    };

    inline static const EntityConfigStruct Smaller{
        .scale = {0.25f, 0.25f, 0.25f},
    };

    inline static const EntityConfigStruct Big{
        .scale = {2.0f, 2.0f, 2.0f},
    };

    inline static const EntityConfigStruct Bigger{
        .scale = {5.0f, 5.0f, 5.0f},
    };

    // ---------- ROTATION PRESETS (degrees) ----------
    inline static const EntityConfigStruct RotateLeft{
        .rotation = {0.0f, -90.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateRight{
        .rotation = {0.0f, 90.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateUp{
        .rotation = {-90.0f, 0.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateDown{
        .rotation = {90.0f, 0.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateBack{
        .rotation = {0.0f, 180.0f, 0.0f},
    };

    inline static const EntityConfigStruct RotateFront{
        .rotation = {0.0f, 0.0f, 0.0f},
    };
};
