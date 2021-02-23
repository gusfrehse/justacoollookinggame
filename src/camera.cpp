#define GLM_FORCE_RADIANS
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "camera.h"

#include <iostream>

Camera::Camera(glm::vec3 position)
    : 
        pos(position),
        next_pos(position),
        dir(glm::vec3(0.0f, 0.0f, -1.0f)),
        right(glm::vec3(1.0f, 0.0f, 0.0f)),
        up(glm::cross(right, dir)),
        speed(20.0f),
        sensitivity(300.0),
	yaw(0.0f),
	pitch(0.0f),
	roll(0.0f)
{}

auto Camera::translate(glm::vec3 where) -> void
{
    next_pos = where;
}

auto Camera::move(glm::vec3 where) -> void
{
    next_pos += where;
}

auto Camera::rotateX(float angle) -> void
{
    if (angle != 0.0f)
    {
        pitch += angle;

	if (pitch > 89.999f)
	    pitch = 89.999f;
	else if (pitch < -89.999f)
	    pitch = -89.999f;
    }
}

auto Camera::rotateY(float angle) -> void
{
    if (angle != 0.0f)
    {
        yaw += angle;
	if (yaw > 359.9f)
	    yaw = 0.1f;
	else if (yaw < 0.1f)
	    yaw = 359.9f;
    }
}

auto Camera::rotateZ(float angle) -> void
{
    if (angle != 0.0f)
    {
        roll += angle;
	if (roll > 189.9f)
	    roll = -190.0f;
	else if (roll < -190.0f)
	    roll = 189.9f;
    }
}

auto Camera::think() -> void
{
    //dir = rot * dir;
    std::cout << "pitch: " << pitch << " yaw:   " << yaw   << " roll:  " << roll << std::endl
	      << "dir.x: " << dir.x << " dir.y: " << dir.y << " dir.z: " << dir.z << std::endl;
    dir.x = glm::cos(glm::radians(yaw));
    dir.y = glm::sin(glm::radians(pitch));
    dir.z = glm::sin(glm::radians(yaw));
    
    right = glm::cross(dir, worldUp);
    right = glm::normalize(right);
    up = glm::cross(right, dir);
    pos = next_pos;
}

auto Camera::genViewMatrix() const -> glm::mat4
{
    return glm::lookAt(pos, pos + dir, worldUp);
}
