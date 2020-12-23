#include "shader_program.h"

#include <iostream>
#include <GL/gl3w.h>

auto ShaderProgram::set(GLenum t, Shader s) -> void
{
    shaders.insert_or_assign(t, s);
}

auto ShaderProgram::log() const -> void
{
    for (const auto& s : shaders)
    {
        switch(s.first)
        {
            case GL_FRAGMENT_SHADER:
                std::cerr << "Log from fragment shader:" << std::endl;
            case GL_VERTEX_SHADER:
                std::cerr << "Log from vertex shader:" << std::endl;
            case GL_GEOMETRY_SHADER:
                std::cerr << "Log from geometry shader:" << std::endl;
            case GL_COMPUTE_SHADER:
                std::cerr << "Log from compute shader:" << std::endl;
        }

        s.second.log();
    }
}

auto ShaderProgram::compile() const -> void
{
    for (const auto& s : shaders)
    {
        s.second.compile();
    }
}

auto ShaderProgram::link() const -> void
{
    for (const auto& s: shaders)
    {
    }
}
