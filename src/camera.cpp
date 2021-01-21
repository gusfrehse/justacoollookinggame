#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "camera.h"

Camera::Camera(glm::vec3 position)
    : 
        pos(position),
        rot(glm::quat(1.0f, 0.0f,  0.0f, 0.0f)),
        dir(glm::vec3(0.0f, 0.0f,  1.0f)),
        right(glm::vec3(1.0f, 0.0f,  0.0f)),
        up(glm::cross(dir, right))
{}

auto Camera::translate(glm::vec3 where) -> void
{
    pos = where;
}

auto Camera::rotate(glm::vec3 axis, float angle) -> void
{
    rot = glm::rotate(rot, angle, axis);
}

auto Camera::think() -> void
{
    dir = rot * dir;
    rot = glm::quat(1.0f, 0.f, 0.f, 0.f);
    right = glm::cross(worldUp, dir);
    up = glm::cross(dir, right);
}

auto Camera::genViewMatrix() const -> glm::mat4
{
    return glm::lookAt(pos, pos + dir, worldUp);
}
