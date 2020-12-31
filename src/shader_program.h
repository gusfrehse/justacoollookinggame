#ifndef GAME_SHADER_PROGRAM_H
#define GAME_SHADER_PROGRAM_H

#include <unordered_map>
#include "shader.h"

class ShaderProgram
{
    GLuint id;
    std::unordered_map<GLenum, Shader> shaders;

public:
    ShaderProgram();
    auto set(Shader &s) -> void;
    auto log() const -> void;
    auto compile() -> void;
    auto link() const -> void;
    auto use() const -> void;
};
#endif
