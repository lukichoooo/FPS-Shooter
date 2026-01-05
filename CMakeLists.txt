cmake_minimum_required(VERSION 3.23)
project(Shooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Executable
add_executable(${PROJECT_NAME} src/main.cpp)

target_sources(${PROJECT_NAME} PRIVATE
    # Core
    src/core/Window.cpp

    # Game
    src/game/Engine.cpp
    src/game/Mesh.cpp

    # Graphics
    src/graphics/Renderer.cpp
    src/graphics/Shader.cpp
)

# Libraries
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    OpenGL::GL
    glm::glm
    GLEW::GLEW
    glfw
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

