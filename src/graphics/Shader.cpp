#include "config/EngineConfig.h"
#include "spdlog/spdlog.h"
#include <GL/glew.h>
#include <GL/glext.h>
#include <cstdlib>
#include <fstream>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <graphics/Shader.h>
#include <sstream>

Shader::Shader(const ShaderConfig &config)
{
    try
    {
        std::ifstream vFile(config.vertexShaderPath);
        std::ifstream fFile(config.fragmentShaderPath);

        vFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        std::stringstream vStream, fStream;
        vStream << vFile.rdbuf();
        fStream << fFile.rdbuf();
        vFile.close();
        fFile.close();
        vertexShaderSource = vStream.str();
        fragmentShaderSource = fStream.str();
    }
    catch (std::ifstream::failure &e)
    {
        spdlog::error("Failed To Read Source Files For Shaders: {}", e.what());
        std::abort();
    }

    if (vertexShaderSource.empty() || fragmentShaderSource.empty())
    {
        if (vertexShaderSource.empty())
            spdlog::error("Specified Vertex Shader Empty: {}, path={}",
                          vertexShaderSource, config.vertexShaderPath);
        if (fragmentShaderSource.empty())
            spdlog::error("Specified Fragment Shader Empty: {}, path={}",
                          fragmentShaderSource, config.fragmentShaderPath);
        std::abort();
    }

    programId = glCreateProgram();
    if (!programId)
    {
        spdlog::error("Failed To Create ShaderClass Object With id={},"
                      "VertexShader={}, FragmentShader={}",
                      programId, vertexShaderSource, fragmentShaderSource);
        std::abort();
    }
}

void Shader::addVertexShader() const { addShader(vertexShaderSource, GL_VERTEX_SHADER); }

void Shader::addFragmentShader() const { addShader(fragmentShaderSource, GL_FRAGMENT_SHADER); }

void Shader::linkProgram() const
{
    GLint linkStatus = 0;
    glLinkProgram(programId);
    glGetProgramiv(programId, GL_LINK_STATUS, &linkStatus);
    if (!linkStatus)
    {
        GLchar logInfo[1024];
        glGetProgramInfoLog(programId, sizeof(logInfo), NULL, logInfo);
        spdlog::error("Shader Program Link Error: error={}, log={}",
                      linkStatus, logInfo);
    }
}

void Shader::setFloat(const char *name, float value) const
{
    glUniform1f(glGetUniformLocation(programId, name), value);
}

void Shader::setMat4f(const char *name, const glm::mat4 &matrix) const
{
    glUniformMatrix4fv(
        glGetUniformLocation(programId, name),
        1,
        GL_FALSE,
        glm::value_ptr(matrix));
}


// private helpers


void Shader::addShader(const std::string &src, GLenum type) const
{
    int shaderId = glCreateShader(type);
    if (!shaderId)
    {
        spdlog::error("Failed To Generate {} Shader", type);
        std::abort();
    }

    const char *constSrc = src.c_str();
    glShaderSource(shaderId, 1, &constSrc, NULL);
    glCompileShader(shaderId);

    GLint compileStatus = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileStatus);
    if (!compileStatus)
    {
        GLchar logInfo[1024];
        glGetShaderInfoLog(shaderId, sizeof(logInfo), NULL, logInfo);
        spdlog::error("{} Shader Compilation Error: error={}, log={}",
                      type, compileStatus, logInfo);
    }

    glAttachShader(programId, shaderId);
}
