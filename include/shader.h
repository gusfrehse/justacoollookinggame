#ifndef GAME_SHADER_H
#define GAME_SHADER_H

#include <GL/gl3w.h>
#include <string>

class Shader
{
public:
    GLuint id = 0;
    GLenum type;
    std::string source;
    bool compile_error = false;

    Shader(GLenum t, const char* path);
    auto compile() const -> void;
    auto log() const -> void;
};
#endif
