#ifndef GAME_SHADER_PROGRAM_H
#define GAME_SHADER_PROGRAM_H

#include <unordered_map>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
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
    auto setUniform(std::string varName, glm::vec3 value) const -> void;
    auto setUniform(std::string varName, glm::vec2 value) const -> void;
    auto setUniform(std::string varName, GLfloat value) const -> void;
    auto setUniform(std::string varName, glm::mat4x4 value) const -> void;
};
#endif
