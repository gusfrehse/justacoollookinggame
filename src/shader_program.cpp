#include "shader_program.h"

#include <iostream>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

extern GLFWwindow* window;

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
	if (!s.second.ready)
	{
	    glfwSetWindowShouldClose(window, true);
	    break;
	}
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
	glfwSetWindowShouldClose(window, true);
    }
}

auto ShaderProgram::setUniform(std::string varName, glm::vec3 value) const -> void
{
    auto location = glGetUniformLocation(id, varName.c_str());
    if (location == -1)
    {
        std::cerr << "'" << varName << "' is not a valid variable name for a uniform" << std::endl;

    }
    glUniform3fv(location, 1, glm::value_ptr(value));
}

auto ShaderProgram::setUniform(std::string varName, glm::vec2 value) const -> void
{
    auto location = glGetUniformLocation(id, varName.c_str());
    if (location == -1)
    {
        std::cerr << "'" << varName << "' is not a valid variable name for a uniform" << std::endl;

    }
    glUniform2fv(location, 1, glm::value_ptr(value));
}

auto ShaderProgram::setUniform(std::string varName, GLfloat value) const -> void
{
    auto location = glGetUniformLocation(id, varName.c_str());
    if (location == -1)
    {
        std::cerr << "'" << varName << "' is not a valid variable name for a uniform" << std::endl;

    }
    glUniform1f(location, value);
}

auto ShaderProgram::setUniform(std::string varName, glm::mat4x4 value) const -> void
{
    auto location = glGetUniformLocation(id, varName.c_str());
    if (location == -1)
    {
        std::cerr << "'" << varName << "' is not a valid variable name for a uniform" << std::endl;

    }
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

auto ShaderProgram::use() const -> void
{
   glUseProgram(id); 
}
