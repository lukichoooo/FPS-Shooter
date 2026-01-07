
#pragma once

#include "config/EngineConfig.h"
#include "graphics/Shader.h"


class ShaderTestsHelper
{
  private:
    EngineConfig config;
    Shader shader;

    ShaderTestsHelper()
        : shader(config.shader)
    {
        shader.addVertexShader();
        shader.addFragmentShader();
        shader.linkProgram();
    }

  public:
    ShaderTestsHelper(const ShaderTestsHelper &) = delete;
    ShaderTestsHelper &operator=(const ShaderTestsHelper &) = delete;
    ShaderTestsHelper(ShaderTestsHelper &&) = delete;
    ShaderTestsHelper &operator=(ShaderTestsHelper &&) = delete;

    static ShaderTestsHelper &getInstance()
    {
        static ShaderTestsHelper instance;
        return instance;
    }

    Shader &getShader() { return shader; }
};


inline Shader &_makeTestShader()
{
    return ShaderTestsHelper::getInstance().getShader();
}
