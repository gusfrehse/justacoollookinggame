#ifndef G_MESH_H
#define G_MESH_H

#include <glm/vec3.hpp>
#include <string>
#include <GL/gl3w.h>


class Mesh
{
public:
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec3> colors;
    
    bool has_color = false;
    glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    bool has_texture = false;
    GLuint vao;
    GLuint vbo;

    auto open(std::string path) -> int;
    auto set_color(glm::vec3 col) -> void;
    auto gen_vao() -> void;
};

#endif
