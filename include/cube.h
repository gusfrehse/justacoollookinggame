#ifndef GAME_CUBE_H
#define GAME_CUBE_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class Cube
{
    static const unsigned int numVertices = 36;
    static const glm::vec3 vertices[36];
    static const glm::vec2 uv[36];
    static const glm::vec3 normals[36];

    //auto createVAO(bool uvs, bool normals) -> GLuint;    
};

#endif
