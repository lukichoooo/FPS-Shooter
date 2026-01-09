#pragma once

#include "config/EngineConfig.h"
#include "core/mesh/MeshFactory.h"
#include "core/entities/DynamicEntity.h"
#include "graphics/Shader.h"
#include "unitTests/testsHelper/ShaderTestsHelper.h"

class DynamicEntityTests
{
  public:
    void
    test_entity_pos()
    {
        EntityConfigStruct cfg;
        cfg.pos = {1.0f, 2.0f, 3.0f};
        cfg.scale = {2.0f, 2.0f, 2.0f};

        MeshFactory factory;
        Mesh *mesh = factory.buildNewSquare();
        Shader shader = _makeTestShader();

        DynamicEntity e(cfg, mesh);

        glm::vec3 pos = e.getPos();

        assert(pos.x == 1.0f);
        assert(pos.y == 2.0f);
        assert(pos.z == 3.0f);
    }


    void test_entity_draw_valid()
    {
        MeshFactory factory;
        Mesh *mesh = factory.buildNewSquare();
        Shader shader = _makeTestShader();

        DynamicEntity e({}, mesh);
        e.draw(shader); // should not crash
    }
};


inline void _dynamicEntityTests()
{
    DynamicEntityTests sut;
    sut.test_entity_draw_valid();
    sut.test_entity_pos();
}
