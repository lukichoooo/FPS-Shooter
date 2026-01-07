#define DEBUG

#include "core/Entity.h"
#include "spdlog/spdlog.h"
#include <glm/ext/matrix_transform.hpp>

Entity::Entity()
    : config(),
      mesh(nullptr),
      shader(nullptr) {}

Entity::Entity(const EntityConfigStruct &config, Mesh *mesh, Shader *shader)
    : config(config),
      mesh(mesh),
      shader(shader),
      pos(config.initialPos),
      rotation(config.initialRotation),
      scale(config.initialScale) {}


void Entity::draw()
{
    if (!mesh)
    {
        spdlog::info("Entity Mesh is null, cant Draw");
        return;
    }

    mesh->bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, pos);
    model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
    model = glm::scale(model, scale);

    shader->use();
    shader->setMat4f("model", model);
    shader->setVec4f("color", mesh->getColor());

    glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, 0);

#ifdef DEBUG
    spdlog::info("Finished Drawing Entity");
#endif
}
