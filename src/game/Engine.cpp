#include "game/Entity.h"
#include "game/Mesh.h"
#include "game/Engine.h"
#include "config/EngineConfig.h"
#include "graphics/Renderer.h"
#include "core/Camera.h"
#include "core/Dtos.h"
#include "core/Input.h"
#include "game/Player.h"
#include "graphics/FrameClock.h"
#include "graphics/Shader.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

Engine::Engine(const EngineConfig &config)
    : config(config),
      window(config.window),
      renderer(config.render) {}


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

    GLuint indices[] = {
        0, 1, 3,
        1, 2, 3};

    Mesh square(vertices, indices, {0.0f, 0.0f, 4.0f, 1.0f});

    SpaceMatrices matrices;

    Camera camera(config.camera);
    Player player(config.player);
    Input input(config.input, window.getHandle());


    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    shader.use();
    input.use();

    Entity entity({{0, 0, 0}}, &square, &shader);

    while (!glfwWindowShouldClose(window.getHandle()))
    {
        renderer.beginFrame();
        FrameClock::updateDeltaTime();

        input.handleKeyInput(player, camera);
        input.handleMouseSensorInput(camera);

        camera.updateView(player.getCharacter().getPos(), matrices);
        camera.updateProjection(matrices);

        shader.setMat4f("view", matrices.view);
        shader.setMat4f("projection", matrices.projection);

        renderer.submit(entity);

        glfwSwapBuffers(window.getHandle());
        glfwPollEvents();
    }

    glfwDestroyWindow(window.getHandle());
    glfwTerminate();
}
