#include "core/StaticEntity.h"

StaticEntity::StaticEntity(EntityConfig config, Mesh *mesh, Shader *shader)
    : config(config),
      mesh(mesh),
      shader(shader)
{
    model = glm::mat4(1.0f);
    model = glm::translate(model, config.initialPos);
    model = glm::rotate(model, config.initialRotation.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, config.initialRotation.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, config.initialRotation.z, glm::vec3(0, 0, 1));
    model = glm::scale(model, config.initialScale);
}


void StaticEntity::draw() const
{
    mesh->bind();
    shader->use();
    shader->setMat4f("model", model);
    shader->setVec4f("color", mesh->getColor());
    glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
}
