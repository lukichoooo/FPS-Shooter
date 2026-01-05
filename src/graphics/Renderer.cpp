#include "graphics/Renderer.h"
#include "config/EngineConfig.h"
#include "core/Window.h"
#include "graphics/Shader.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer(const RenderConfig &config, Window &window)
    : renderConfig(config),
      window(window)
{
    glEnable(GL_DEPTH_TEST);
}


void Renderer::clear() const
{
    glClearColor(
        renderConfig.clearColor.r,
        renderConfig.clearColor.g,
        renderConfig.clearColor.b,
        renderConfig.clearColor.a);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(
    const Mesh &mesh,
    const Shader &shader,
    [[maybe_unused]] const SpaceMatrices &matrices)
    const
{
    shader.use();
    glBindVertexArray(mesh.getVAO());

    shader.setMat4f("model", glm::value_ptr(matrices.view));
    // shader.setMat4f("view", glm::value_ptr(matrices.model));

    glDrawArrays(GL_TRIANGLES, 0, mesh.getIndexCount());

    glfwSwapBuffers(window.getHandle());
};
