#ifndef GAME_SHADER_H
#define GAME_SHADER_H

#include <GL/gl3w.h>
#include <string>

class Shader
{
public:
    GLuint id = 0;
    GLenum type;
    char* source;
    bool ready = true;

    Shader(GLenum t, const char* path);
    auto compile() -> void;
};
#endif
