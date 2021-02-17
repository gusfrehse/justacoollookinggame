#include <GL/gl3w.h>
#include <string>

class Mesh
{
    Mesh();
    auto open(std::string path) -> void;
    //auto toVAO() -> GLint;
};
