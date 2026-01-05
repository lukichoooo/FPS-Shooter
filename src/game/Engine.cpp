#include "config/EngineConfig.h"
#include "core/Dtos.h"
#include "game/Engine.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

Engine::Engine(const EngineConfig &cfg)
    : config(cfg),
      window(cfg.window),
      renderer(cfg.render, window),
      shader(cfg.shader)
{
    shader.addVertexShader();
    shader.addFragmentShader();
    shader.linkProgram();
    shader.use();
}


void Engine::run()
{
    Vertex vertices[] = {
        {{-1.0f, -1.0f, 0.0f}},
        {{-1.0f, 1.0f, 0.0f}},
        {{1.0f, 1.0f, 0.0f}},
        {{0.0f, 0.0f, 1.5f}},
    };

    GLuint indices[] = {0, 1, 2,
                        0, 1, 3,
                        0, 2, 3,
                        1, 2, 3};

    Mesh mesh;
    mesh.createMesh(vertices, indices);

    SpaceMatrices matrices;
    matrices.projection = glm::perspective(
        glm::radians(65.0f),
        (float)config.window.width / (float)config.window.height,
        0.1f,
        100.0f);
    shader.setMat4f("projection", glm::value_ptr(matrices.projection));

    while (!glfwWindowShouldClose(window.getHandle()))
    {
        renderer.clear();

        matrices.model = glm::mat4(1.0f);
        // matrices.view =

        renderer.draw(mesh, shader, matrices);

        // Game update & render calls go here

        glfwSwapBuffers(window.getHandle());
        glfwPollEvents();
    }
}
