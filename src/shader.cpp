#include "shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(GLenum t, const char* path) :
    type(t), id(glCreateShader(type))
{
    std::ostringstream ss;

    std::ifstream file(path);
    if (!file.good())
    {
        std::cerr << "Could not open file: " << path << std::endl;
    }
    else
    {
        ss << file.rdbuf();
        source = ss.str();
    } 
}

auto Shader::compile() const -> void
{
    const char *c_str = source.c_str();
    glShaderSource(id, 1, &c_str, NULL);
    glCompileShader(id);
}

auto Shader::log() const -> void
{
    GLint compiled;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        GLsizei len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);

        auto log = new GLchar[len + 1];
        glGetShaderInfoLog(id, len, &len, log);
        std::cerr << "Compile shader error:\n" << log << std::endl;
        delete [] log;
    }
}
