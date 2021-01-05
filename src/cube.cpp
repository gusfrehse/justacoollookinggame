#include "cube.h"

static auto Cube::getVertices() -> float const[36]
{
     const glm::vec3 vertices[] = {
        glm::vec3( 1.0f,  1.0f, -1.0f), // FACE +X TRIANGLE 1 VERTEX A
        glm::vec3( 1.0f,  1.0f,  1.0f), // FACE +X TRIANGLE 1 VERTEX B
        glm::vec3( 1.0f, -1.0f,  1.0f), // FACE +X TRIANGLE 1 VERTEX C
        glm::vec3( 1.0f, -1.0f, -1.0f), // FACE +X TRIANGLE 2 VERTEX A
        glm::vec3( 1.0f, -1.0f, -1.0f), // FACE +X TRIANGLE 2 VERTEX B
        glm::vec3( 1.0f, -1.0f, -1.0f), // FACE +X TRIANGLE 2 VERTEX c
                                                
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE -X TRIANGLE 1 VERTEX A
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE -X TRIANGLE 1 VERTEX B
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE -X TRIANGLE 1 VERTEX C
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE -X TRIANGLE 2 VERTEX A
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE -X TRIANGLE 2 VERTEX B
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE -X TRIANGLE 2 VERTEX c
                                                
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE +Y TRIANGLE 1 VERTEX A
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE +Y TRIANGLE 1 VERTEX B
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE +Y TRIANGLE 1 VERTEX C
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE +Y TRIANGLE 2 VERTEX A
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE +Y TRIANGLE 2 VERTEX B
        glm::vec3(-1.0f,  1.0f, -1.0f), // FACE +Y TRIANGLE 2 VERTEX c
                                                
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Y TRIANGLE 1 VERTEX A
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Y TRIANGLE 1 VERTEX B
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Y TRIANGLE 1 VERTEX C
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Y TRIANGLE 2 VERTEX A
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Y TRIANGLE 2 VERTEX B
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Y TRIANGLE 2 VERTEX c
                                                
        glm::vec3(-1.0f, -1.0f,  1.0f), // FACE +Z TRIANGLE 1 VERTEX A
        glm::vec3(-1.0f, -1.0f,  1.0f), // FACE +Z TRIANGLE 1 VERTEX B
        glm::vec3(-1.0f, -1.0f,  1.0f), // FACE +Z TRIANGLE 1 VERTEX C
        glm::vec3(-1.0f, -1.0f,  1.0f), // FACE +Z TRIANGLE 2 VERTEX A
        glm::vec3(-1.0f, -1.0f,  1.0f), // FACE +Z TRIANGLE 2 VERTEX B
        glm::vec3(-1.0f, -1.0f,  1.0f), // FACE +Z TRIANGLE 2 VERTEX c
                                                
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Z TRIANGLE 1 VERTEX A
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Z TRIANGLE 1 VERTEX B
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Z TRIANGLE 1 VERTEX C
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Z TRIANGLE 2 VERTEX A
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Z TRIANGLE 2 VERTEX B
        glm::vec3(-1.0f, -1.0f, -1.0f), // FACE -Z TRIANGLE 2 VERTEX c
    };
}
