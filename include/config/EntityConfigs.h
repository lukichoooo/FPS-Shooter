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
        .pos = {-25.0f, 0.0f, -25.0f},
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

    // ---------- PLACEMENT PRESETS (units) ----------
    inline static const EntityConfigStruct PlaceCenter{
        .pos = {0.0f, 0.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceForward{
        .pos = {0.0f, 0.0f, -20.0f},
    };

    inline static const EntityConfigStruct PlaceBack{
        .pos = {0.0f, 0.0f, 20.0f},
    };

    inline static const EntityConfigStruct PlaceLeft{
        .pos = {-20.0f, 0.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceRight{
        .pos = {20.0f, 0.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceForwardLeft{
        .pos = {-20.0f, 0.0f, -20.0f},
    };

    inline static const EntityConfigStruct PlaceForwardRight{
        .pos = {20.0f, 0.0f, -20.0f},
    };

    inline static const EntityConfigStruct PlaceBackLeft{
        .pos = {-20.0f, 0.0f, 20.0f},
    };

    inline static const EntityConfigStruct PlaceBackRight{
        .pos = {20.0f, 0.0f, 20.0f},
    };


    // ---------- AIR / VERTICAL PLACEMENT PRESETS ----------
    inline static const EntityConfigStruct PlaceSlightlyAbove{
        .pos = {0.0f, 5.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceAbove{
        .pos = {0.0f, 10.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceHighAbove{
        .pos = {0.0f, 20.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceSlightlyBelow{
        .pos = {0.0f, -5.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceBelow{
        .pos = {0.0f, -10.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceDeepBelow{
        .pos = {0.0f, -20.0f, 0.0f},
    };

    // ---------- COMBINED AIR + HORIZONTAL ----------
    inline static const EntityConfigStruct PlaceAboveForward{
        .pos = {0.0f, 10.0f, -10.0f},
    };

    inline static const EntityConfigStruct PlaceAboveBack{
        .pos = {0.0f, 10.0f, 10.0f},
    };

    inline static const EntityConfigStruct PlaceAboveLeft{
        .pos = {-10.0f, 10.0f, 0.0f},
    };

    inline static const EntityConfigStruct PlaceAboveRight{
        .pos = {10.0f, 10.0f, 0.0f},
    };
};
