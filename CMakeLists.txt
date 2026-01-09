cmake_minimum_required(VERSION 3.23)
project(Shooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Libraries
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Create a library for all game code
add_library(GameCore STATIC
    # Core
    src/core/Window.cpp
    src/core/Camera.cpp
    src/core/Input.cpp
    src/core/MeshFactory.cpp
    src/core/Mesh.cpp

    src/core/entities/DynamicEntity.cpp
    src/core/entities/StaticEntity.cpp
    src/core/entities/EntityBuilder.cpp

    # Game
    src/game/Engine.cpp
    src/game/Player.cpp
    src/game/WorldBuilder.cpp
    src/game/Scene.cpp

    src/game/entities/Character.cpp

    # Graphics
    src/graphics/Renderer.cpp
    src/graphics/FrameClock.cpp
    src/graphics/Shader.cpp
)

target_include_directories(GameCore PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/external
)

target_link_libraries(GameCore PUBLIC
    OpenGL::GL
    glm::glm
    GLEW::GLEW
    glfw
)

target_compile_options(GameCore PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -g
    -O0
)

# Executable
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(Shooter PRIVATE GameCore)

# Testing Executable
add_executable(Tests tests/unitTests/Tests.cpp)
target_link_libraries(Tests PRIVATE GameCore)

target_include_directories(Tests PRIVATE
    ${PROJECT_SOURCE_DIR}/tests
)


# Include paths
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/external
)

# compiler options
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -g
    -O0
)

add_custom_target(copy_shaders ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory
        ${CMAKE_BINARY_DIR}/assets/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/shaders
        ${CMAKE_BINARY_DIR}/assets/shaders
    COMMENT "Updating shaders"
)

add_custom_target(copy_configs ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory
        ${CMAKE_BINARY_DIR}/assets/config
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/config
        ${CMAKE_BINARY_DIR}/assets/config
    COMMENT "Updating shaders"
)




