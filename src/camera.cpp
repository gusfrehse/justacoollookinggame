#define GLM_FORCE_RADIANS
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "camera.h"

#include <iostream>

extern double deltaTime;

Camera::Camera(glm::vec3 position)
    : 
        pos(position),
        target_dir(position),
        dir(glm::vec3(0.0f, 0.0f, -1.0f)),
        right(glm::vec3(1.0f, 0.0f, 0.0f)),
        up(glm::cross(right, dir)),
        speed(20.0f),
        sensitivity(10.0),
	    yaw(0.0f),
	    pitch(0.0f),
	    roll(0.0f),
        friction_coef(0.2f)
{}

auto Camera::translate(glm::vec3 where) -> void
{
    target_dir = where;
}

auto Camera::move(glm::vec3 where) -> void
{
    target_dir += where;
}

auto Camera::rotateX(float angle) -> void
{
    if (angle != 0.0f)
    {
        pitch += angle;

	if (pitch > 89.0f)
	    pitch = 89.0f;
	else if (pitch < -89.0f)
	    pitch = -89.0f;
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
    // dir calculation
    dir.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    dir.y = glm::sin(glm::radians(pitch));
    dir.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    dir = glm::normalize(dir);

    // right and up calculation
    right = glm::cross(dir, worldUp);
    right = glm::normalize(right);
    up = glm::cross(right, dir);

    // position calculation
    pos += (target_dir - pos)
                 * friction_coef * (float) deltaTime;
}

auto Camera::genViewMatrix() const -> glm::mat4
{
    return glm::lookAt(pos, pos + dir, worldUp);
}
