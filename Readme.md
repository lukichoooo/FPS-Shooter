### FPS Shooter (OpenGL)

A simple 3D FPS-style game built with modern OpenGL using C++, GLFW, and GLEW.
The project is built with CMake and Ninja.

# Tech Stack

- C++

- OpenGL

- GLFW – windowing & input

- GLEW – OpenGL function loading

- CMake – build system

- Ninja – fast build backend

# Build Instructions (Linux)

1. Generate build files
```yaml
cmake -B build/ -G Ninja
```

2. Build the project
```yaml
cmake --build build/
```

During build, shaders are automatically updated:

[2/2] Updating shaders

Run the Game
./build/Shooter

# Controls

- Mouse — Look around

- Keyboard — Movement

- ESC — Exit the game
