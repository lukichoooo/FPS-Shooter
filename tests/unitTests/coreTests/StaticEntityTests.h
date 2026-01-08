#pragma once

#include "config/EngineConfig.h"
#include "core/MeshFactory.h"
#include "core/entities/StaticEntity.h"
#include "graphics/Shader.h"
#include "unitTests/testsHelper/ShaderTestsHelper.h"


class StaticEntityTests
{
  public:
    void
    test_staticEntity_model()
    {
        EntityConfigStruct cfg;
        cfg.pos = {1.0f, 2.0f, 3.0f};
        cfg.scale = {2.0f, 2.0f, 2.0f};

        MeshFactory factory;
        Mesh *mesh = factory.buildNewSquare();
        Shader shader = _makeTestShader();

        StaticEntity e(cfg, mesh);

        glm::mat4 model = e.getModel();
        glm::vec3 pos = glm::vec3(model[3]);

        assert(pos.x == 1.0f);
        assert(pos.y == 2.0f);
        assert(pos.z == 3.0f);
    }


    void test_staticEntity_draw_valid()
    {
        MeshFactory factory;
        Mesh *mesh = factory.buildNewSquare();
        Shader shader = _makeTestShader();

        StaticEntity e({}, mesh);
        e.draw(shader); // should not crash
    }
};


inline void _staticEntityTests()
{
    StaticEntityTests sut;
    sut.test_staticEntity_draw_valid();
    sut.test_staticEntity_model();
}
