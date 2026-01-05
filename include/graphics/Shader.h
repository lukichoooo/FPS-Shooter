#pragma once

#include "config/EngineConfig.h"
#include <GL/glew.h>
#include <string>

class Shader
{
  private:
    int programId{};
    std::string vertexShaderSource{};
    std::string fragmentShaderSource{};
    void addShader(const std::string &src, GLenum type) const;

  public:
    Shader(const ShaderConfig &config);

    int getShaderId() const { return programId; }
    void use() const { glUseProgram(programId); };

    // @brief add stored vertex shader to this shader program
    void addVertexShader() const;

    // @brief add stored fragment shader to this shader program
    void addFragmentShader() const;

    void linkProgram() const;

    // @brief after glUseProgram
    void setFloat(const char *name, float value) const;

    // @brief after glUseProgram
    void setMat4f(const char *name, const float *matrix) const;
};
