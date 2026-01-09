#include "core/mesh/Mesh.h"
#include "graphics/Shader.h"
#include "spdlog/spdlog.h"
#include "core/entities/StaticEntity.h"

StaticEntity::StaticEntity()
    : mesh(nullptr) {}

StaticEntity::StaticEntity(EntityConfigStruct config, Mesh *mesh)
    : config(config),
      mesh(mesh),
      color(config.color)
{
    model = glm::mat4(1.0f);
    model = glm::translate(model, config.pos);
    model = glm::rotate(model, config.rotation.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, config.rotation.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, config.rotation.z, glm::vec3(0, 0, 1));
    model = glm::scale(model, config.scale);
}


void StaticEntity::draw(Shader &shader) const
{
    if (!mesh)
    {
        spdlog::info("StaticEntity Mesh is null, cant Draw");
        return;
    }

    mesh->bind();
    shader.use();
    shader.setMat4f("model", model);
    shader.setVec4f("color", color);

    glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, 0);

#ifdef DEBUG_ENTITIES
    spdlog::info("Finished Drawing StaticEntity");
#endif
}
