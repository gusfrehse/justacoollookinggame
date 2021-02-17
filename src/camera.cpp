#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "camera.h"

#include <iostream>

Camera::Camera(glm::vec3 position)
    : 
        pos(position),
        next_pos(position),
        rot(glm::quat(1.0f, 0.0f,  0.0f, 0.0f)),
        dir(glm::vec3(0.0f, 0.0f,  -1.0f)),
        right(glm::vec3(1.0f, 0.0f,  0.0f)),
        up(glm::cross(right, dir)),
        speed(0.1),
        sensitivity(0.005)
{}

auto Camera::translate(glm::vec3 where) -> void
{
    next_pos = where;
}

auto Camera::move(glm::vec3 where) -> void
{
    next_pos += where;
}

auto Camera::rotate(glm::vec3 axis, float angle) -> void
{
    if (angle != 0.0f)
    {
        rot = glm::rotate(rot, angle, axis);
    }
}

auto Camera::think() -> void
{
    dir = rot * dir;
    rot = glm::quat(1.0f, 0.f, 0.f, 0.f);
    right = glm::cross(dir, worldUp);
    right = glm::normalize(right);
    up = glm::cross(right, dir);
    pos = next_pos;
    std::cout << "camera right"
        << " x: " << right.x
        << " y: " << right.y
        << " z: " << right.z
        << " length: " << glm::length(right)
        << std::endl;
}

auto Camera::genViewMatrix() const -> glm::mat4
{
    return glm::lookAt(pos, pos + dir, worldUp);
}
