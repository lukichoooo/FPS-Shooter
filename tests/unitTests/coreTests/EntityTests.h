#pragma once

#include "config/EngineConfig.h"
#include "core/Entity.h"
#include "core/MeshFactory.h"
#include "graphics/Shader.h"
#include "unitTests/testsHelper/ShaderTestsHelper.h"

class EntityTests
{
  public:
    void
    test_entity_pos()
    {
        EntityConfigStruct cfg;
        cfg.initialPos = {1.0f, 2.0f, 3.0f};
        cfg.initialScale = {2.0f, 2.0f, 2.0f};

        MeshFactory factory;
        Mesh *mesh = factory.buildSquare({1, 1, 1, 1});
        Shader shader = _makeTestShader();

        Entity e(cfg, mesh, &shader);

        glm::vec3 pos = e.getPos();

        assert(pos.x == 1.0f);
        assert(pos.y == 2.0f);
        assert(pos.z == 3.0f);
    }


    void test_entity_draw_valid()
    {
        MeshFactory factory;
        Mesh *mesh = factory.buildSquare({0, 1, 0, 1});
        Shader shader = _makeTestShader();

        Entity e({}, mesh, &shader);
        e.draw(); // should not crash
    }
};


inline void _entityTests()
{
    EntityTests sut;
    sut.test_entity_draw_valid();
    sut.test_entity_pos();
}
