#include "config/EngineConfig.h"
#include "core/Dtos.h"
#include "game/Engine.h"
#include <GL/gl.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

Engine::Engine(const EngineConfig &cfg)
    : config(cfg),
      window(cfg.window),
      renderer(cfg.render, window) {}


void Engine::run()
{

    Shader shader(config.shader);
    shader.addVertexShader();
    shader.addFragmentShader();
    shader.linkProgram();
    shader.use();

    Vertex vertices[] = {
        {{-1.0, 1.0, 0.0}},
        {{1.0, 1.0, 0.0}},
        {{1.0, -1.0, 0.0}},
        {{-1.0, -1.0, -1.0}},
    };

    GLuint indices[] = {0, 1, 3,
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

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window.getHandle()))
    {
        renderer.clear();

        matrices.model = glm::mat4(1.0f);
        matrices.model = glm::scale(matrices.model, glm::vec3(0.5f));

        matrices.view = glm::lookAt(
            glm::vec3(0.0f, 0.0f, 5.0f), // camera position
            glm::vec3(0.0f, 0.0f, 0.0f), // target
            glm::vec3(0.0f, 1.0f, 0.0f)  // up
        );

        renderer.draw(mesh, shader, matrices);


        glfwSwapBuffers(window.getHandle());
        glfwPollEvents();
    }
}
