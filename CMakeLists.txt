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

# Remove old shaders from build directory
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/assets/shaders)

# Copy shaders into build directory for runtime access
file(COPY
    ${CMAKE_CURRENT_SOURCE_DIR}/assets/shaders
    DESTINATION ${CMAKE_BINARY_DIR}/assets
)

