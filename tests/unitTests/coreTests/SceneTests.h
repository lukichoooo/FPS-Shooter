#pragma once

#include <cassert>
#include "core/MeshFactory.h"
#include "core/entities/StaticEntity.h"
#include "core/Scene.h"
#include "unitTests/testsHelper/ShaderTestsHelper.h"


// Minimal static entity creator
inline StaticEntity _makeStaticEntity()
{
    MeshFactory factory;
    Mesh *mesh = factory.buildNewSquare();
    Shader shader = _makeTestShader();
    EntityConfigStruct cfg;
    return StaticEntity(cfg, mesh);
}

// Minimal dynamic entity creator
inline DynamicEntity _makeDynamicEntity()
{
    MeshFactory factory;
    Mesh *mesh = factory.buildNewSquare();
    Shader shader = _makeTestShader();
    CharacterConfig cfg;
    return DynamicEntity(cfg, mesh);
}

class SceneTests
{
  public:
    void test_scene_constructor()
    {
        StaticEntity s1 = _makeStaticEntity();
        StaticEntity s2 = _makeStaticEntity();
        DynamicEntity e1 = _makeDynamicEntity();

        Scene scene({s1, s2}, {e1});

        assert(scene.getStaticEntities().size() == 2);
        assert(scene.getDynamicEntities().size() == 1);
    }

    void test_scene_add()
    {
        Scene scene({}, {});

        StaticEntity s = _makeStaticEntity();
        DynamicEntity e = _makeDynamicEntity();

        scene.addStatic(s);
        scene.addDynamic(e);

        auto statics = scene.getStaticEntities();
        auto dynamics = scene.getDynamicEntities();

        assert(statics.size() == 1);
        assert(dynamics.size() == 1);
    }

    void test_scene_overflow()
    {
        Scene scene({}, {});

        for (size_t i = 0; i < SceneConfig::staticEntitiesSize; ++i)
        {
            scene.addStatic(_makeStaticEntity());
        }

        // One too many → should safely ignore or assert
        scene.addStatic(_makeStaticEntity());
        assert(scene.getStaticEntities().size() == SceneConfig::staticEntitiesSize);
    }
};

inline void _sceneTests()
{
    SceneTests sut;
    sut.test_scene_constructor();
    sut.test_scene_add();
    sut.test_scene_overflow();
}
