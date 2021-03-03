#ifndef G_MESH_H
#define G_MESH_H

#include <glm/vec3.hpp>
#include <string>

class Mesh
{
public:
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    
    auto open(std::string path) -> int;
    //auto toVAO() -> GLint;
};

#endif
