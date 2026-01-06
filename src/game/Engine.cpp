#include "game/Engine.h"
#include "config/EngineConfig.h"
#include "core/Camera.h"
#include "core/Dtos.h"
#include "core/Input.h"
#include "game/Entities/Player.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

Engine::Engine(const EngineConfig &cfg)
    : config(cfg),
      window(cfg.window),
      renderer(cfg.render, window) {}


FrameClock frameClock;

void updateDeltaTime()
{
    float currentFrame = glfwGetTime();
    frameClock.deltaTime = currentFrame - frameClock.lastFrame;
    frameClock.lastFrame = currentFrame;
}

void Engine::run()
{
    Shader shader(config.shader);
    shader.addVertexShader();
    shader.addFragmentShader();
    shader.linkProgram();

    Vertex vertices[] = {
        {{-1.0, 1.0, 0.0}},
        {{1.0, 1.0, 0.0}},
        {{1.0, -1.0, 0.0}},
        {{-1.0, -1.0, 0.0}},
    };

    GLuint indices[] = {0, 1, 3,
        1, 2, 3};

    Mesh squares[1];
    squares[0].createMesh(vertices, indices);

    SpaceMatrices matrices;

    Camera camera(config.camera);
    Player player(config.player);
    Input input(config.input, window.getHandle(), frameClock);


    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    shader.use();
    input.use();


    while (!glfwWindowShouldClose(window.getHandle()))
    {
        updateDeltaTime();

        input.handleKeyInput(player, camera);
        input.handleMouseSensorInput(camera);

        camera.updateView(player, matrices);
        camera.updateProjection(matrices);

        shader.setMat4f("view", matrices.view);
        shader.setMat4f("projection", matrices.projection);

        renderer.clear();
        renderer.draw(squares, shader, matrices);

        glfwSwapBuffers(window.getHandle());
        glfwPollEvents();
    }

    glfwDestroyWindow(window.getHandle());
    glfwTerminate();
}
