#ifndef GAME_CUBE_H
#define GAME_CUBE_H

#include <glm/vec3.hpp>

class Cube
{
    static const numVertices = 36;
    static const glm::vec3 vertices[36];
    static const glm::vec2[36] uv;
    static const glm::vec3[36] normals;

    auto createVAO(bool uvs, bool normals) -> GLuint;    
};

#endif
