#pragma once

#include "config/EngineConfig.h"
#include "core/MeshFactory.h"
#include "core/StaticEntity.h"
#include "graphics/Shader.h"
#include "unitTests/testsHelper/ShaderTestsHelper.h"


class StaticEntityTests
{
  public:
    void
    test_staticEntity_model()
    {
        EntityConfigStruct cfg;
        cfg.initialPos = {1.0f, 2.0f, 3.0f};
        cfg.initialScale = {2.0f, 2.0f, 2.0f};

        MeshFactory factory;
        Mesh *mesh = factory.buildSquare({1, 1, 1, 1});
        Shader shader = _makeTestShader();

        StaticEntity e(cfg, mesh, &shader);

        glm::mat4 model = e.getModel();
        glm::vec3 pos = glm::vec3(model[3]);

        assert(pos.x == 1.0f);
        assert(pos.y == 2.0f);
        assert(pos.z == 3.0f);
    }


    void test_staticEntity_draw_valid()
    {
        MeshFactory factory;
        Mesh *mesh = factory.buildSquare({0, 1, 0, 1});
        Shader shader = _makeTestShader();

        StaticEntity e({}, mesh, &shader);
        e.draw(); // should not crash
    }
};


inline void _staticEntityTests()
{
    StaticEntityTests sut;
    sut.test_staticEntity_draw_valid();
    sut.test_staticEntity_model();
}
