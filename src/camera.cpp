#include <glm/vec3.hpp>
#include <glm/mat4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"

Camera;:Camera(glm::vec3 position)
    : 
        pos(  glm::vec3(0.0f, 0.0f,  0.0f)),
        rot(  glm::vec3(0.0f, 0.0f,  0.0f)),
        dir(  glm::vec3(0.0f, 0.0f, -1.0f)),
        right(glm::vec3(1.0f, 0.0f,  0.0f)),
        up(glm::cross(dir, right)),
{}

auto Camera::translate(glm::vec3 where) -> void
{
    
}

auto translate(glm::vec3 where) -> void
{
    pos = where;
}

// sets the rotatation to how, not increment it.
auto rotate(glm::vec3 how) -> void
{
    rot = how;
}

auto think() -> void
{
    dir.x = 
}

auto genViewMatrix() const -> glm::mat4
{
    
}
