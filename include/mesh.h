#include <glm/vec3.hpp>
#include <string>

class Mesh
{
public:
    std::vector<glm::vec3> vertices;
    auto open(std::string path) -> int;
    //auto toVAO() -> GLint;
};
