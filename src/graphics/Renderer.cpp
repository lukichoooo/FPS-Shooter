#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>


Renderer::Renderer(const RenderConfig &config)
    : config(config)
{
    glEnable(GL_DEPTH_TEST);
}

void Renderer::clear() const
{
    glClearColor(
        config.clearColor.r,
        config.clearColor.g,
        config.clearColor.b,
        config.clearColor.a);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(
    const Mesh &mesh,
    const Shader &shader,
    SpaceMatrices &matrices)
{
    glBindVertexArray(mesh.getVAO());

    // TODO: move those out
    matrices.model = glm::mat4(1.0f);
    matrices.model = glm::scale(matrices.model, glm::vec3(0.5f));

    shader.setMat4f("model", matrices.model);

    glDrawElements(GL_TRIANGLES, mesh.getIndexCount(), GL_UNSIGNED_INT, 0);
};
