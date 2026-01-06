#include "graphics/Renderer.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer(const RenderConfig &config, Window &window)
    : config(config),
      window(window)
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
    const std::span<Mesh> meshes,
    const Shader &shader,
    SpaceMatrices &matrices)
    const
{

    for (const Mesh &mesh : meshes)
    {
        glBindVertexArray(mesh.getVAO());

        // TODO: move those out
        matrices.model = glm::mat4(1.0f);
        matrices.model = glm::scale(matrices.model, glm::vec3(0.5f));

        shader.setMat4f("model", matrices.model);

        glDrawElements(GL_TRIANGLES, mesh.getIndexCount(), GL_UNSIGNED_INT, 0);
    }
};
