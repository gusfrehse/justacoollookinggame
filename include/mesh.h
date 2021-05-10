#ifndef G_MESH_H
#define G_MESH_H

#include <glm/vec3.hpp>
#include <string>
#include <GL/gl3w.h>
#include <glm/mat4x4.hpp>
#include <vector>


class Mesh
{
public:
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec3> colors;

    glm::mat4x4 model;
    
    bool has_color = false;
    glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    bool has_texture = false;
    GLuint vao;
    GLuint vbo;

    Mesh(std::string path);
    auto set_color(glm::vec3 col) -> void;
    auto gen_vao() -> void;
    auto draw() -> void;
};

#endif
