#include "shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(GLenum t, const char* path) :
    type(t), id(glCreateShader(t))
{
    FILE* shaderSource;
    shaderSource = fopen(path, "r");
    if (!shaderSource)
    {
        std::cerr << "Could not open " << path << " shader." << std::endl;
        source = NULL;
    }
    else
    {
        fseek(shaderSource, 0, SEEK_END);
        int len = ftell(shaderSource);
        fseek(shaderSource, 0, SEEK_SET);

        source = new GLchar[len + 1];
        source[len] = 0;

        fread(source, 1, len, shaderSource);
        fclose(shaderSource);
    }
}

auto Shader::compile() -> void
{
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    GLint compiled;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        std::cerr << "Compile shader error:\n" << std::endl;
        if (!glIsShader(id))
        {
            std::cerr << "is not Shader!" << std::endl;
        }
        ready = false;
        GLint len = 0;
        GLint maxLen = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLen);

        GLchar* log = new GLchar[maxLen + 1];
        glGetShaderInfoLog(id, maxLen, &len, log);
        std::cerr << log << std::endl;
        delete [] log;
    }
    else
    {
        ready = true;
    }
}
