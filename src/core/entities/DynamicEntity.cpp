#include "core/pch.hpp"
#include "core/entities/DynamicEntity.h"

DynamicEntity::DynamicEntity()
    : config(),
      mesh(nullptr) {}


DynamicEntity::DynamicEntity(const EntityConfigStruct &config, Mesh *mesh)
    : config(config),
      mesh(mesh),
      pos(config.pos),
      rotation(config.rotation),
      scale(config.scale),
      color(config.color) {}


void DynamicEntity::draw(Shader &shader)
{
    if (!mesh)
    {
        spdlog::info("Entity Mesh is null, cant Draw");
        return;
    }

    mesh->bind();

    // TODO add animations or somth
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, pos);
    model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
    model = glm::scale(model, scale);

    shader.use();
    shader.setMat4f("model", model);
    shader.setVec4f("color", color);

    glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, 0);

#ifdef DEBUG_ENTITIES
    spdlog::info("Finished Drawing Entity");
#endif
}
