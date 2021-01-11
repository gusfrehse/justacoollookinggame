#include <glm/vec3.hpp>
#include <glm/mat4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"

Camera;:Camera()
    : pos(glm::vec3(0.0f, 0.0f, 0.0f)),
      rot(glm::vec3(0.0f, 0.0f, 0.0f))
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

auto lookAt(glm::vec3 where) -> void
{
    // TODO
}

auto genViewMatrix() const -> glm::mat4
{

}
