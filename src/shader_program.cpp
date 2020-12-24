#include "shader_program.h"

#include <iostream>
#include <GL/gl3w.h>

ShaderProgram::ShaderProgram()
    : id(glCreateProgram())
{}

auto ShaderProgram::set(Shader &s) -> void
{
    shaders.insert_or_assign(s.type, s);
}

auto ShaderProgram::log() const -> void
{
    std::cerr << "SHADER PROGRAM LOG:" << std::endl;
    for (const auto& s : shaders)
    {
        if (glIsShader(s.second.id))
        {
            switch(s.first)
            {
                case GL_FRAGMENT_SHADER:
                    std::cerr << "Fragment shader:" << std::endl;
                    break;
                case GL_VERTEX_SHADER:
                    std::cerr << "Vertex shader:" << std::endl;
                    break;
                case GL_GEOMETRY_SHADER:
                    std::cerr << "Geometry shader:" << std::endl;
                    break;
                case GL_COMPUTE_SHADER:
                    std::cerr << "Compute shader:" << std::endl;
                    break;
                default:
                    std::cerr << "Unknown shader:" << std::endl;
            }

            if (!s.second.ready)
            {
            
                std::cerr << "-> is not ready." << std::endl;
            }
            std::cerr << s.second.source << std::endl;
        }
        else
        {
            std::cerr << "Not a shader" << std::endl;
        }
    }

    if (glIsProgram(id))
    {
    }
    else
    {
        std::cerr << "Not a valid shader program" << std::endl;
    }
}

auto ShaderProgram::compile() -> void
{
    for (auto&& s : shaders)
    {
        s.second.compile();
    }
}

auto ShaderProgram::link() const -> void
{
    for (const auto& s : shaders)
    {
        glAttachShader(id, s.second.id);
    }

    glLinkProgram(id);

    GLint linked;
    glGetProgramiv(id, GL_LINK_STATUS, &linked);
    if (!linked) {
        GLsizei len;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &len);

        GLchar* log = new GLchar[len+1];
        glGetProgramInfoLog(id, len, &len, log);
        std::cerr << "Shader linking failed:\n" << log << std::endl;
    }
}

auto ShaderProgram::use() const -> void
{
   glUseProgram(id); 
}
