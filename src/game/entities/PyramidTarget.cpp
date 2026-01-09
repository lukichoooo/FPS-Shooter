#include "game/entities/PyramidTarget.h"
#include "config/EngineConfig.h"
#include "core/entities/DynamicEntity.h"
#include "game/animation/FlyingTargetAnimator.h"
#include "spdlog/spdlog.h"
#include <cstdlib>
#include <glm/ext/matrix_transform.hpp>


PyramidTarget::PyramidTarget()
    : config(),
      animator(config.animatorConfig) {}

PyramidTarget::PyramidTarget(const FlyingTargetConfig &config, Mesh *pyramidMesh)
    : DynamicEntity(config, pyramidMesh),
      config(config),
      animator(config.animatorConfig)
{
    if (!pyramidMesh)
    {
        spdlog::error("Pyramid Mesh is Null for PyramidTarget");
        std::abort();
    }
}


void PyramidTarget::fly(glm::vec3 &movement)
{
    animator.updatePosDirectedBoost(pos, movement);
}

void PyramidTarget::boost(glm::vec3 &movement)
{
    animator.updatePosDirectedFly(pos, movement);
}

void PyramidTarget::drop()
{
    animator.drop(pos);
}

void PyramidTarget::draw(Shader &shader)
{
    mesh->bind();

    animator.updatePos(pos);
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
    spdlog::info("Finished Drawing Pyramid");
#endif
}
