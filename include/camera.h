#ifndef G_CAMERA_H
#define G_CAMERA_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>

class Camera
{
public:
    static constexpr auto worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 up;
    glm::vec3 right;

    glm::vec3 pos;
    glm::quat rot; // cos(angle/2), axis
    glm::vec3 dir;

    Camera(glm::vec3 position);
    
    auto translate(glm::vec3 where) -> void;
    auto rotate(glm::vec3 axis, float angle) -> void;
    auto think() -> void;
    auto genViewMatrix() const -> glm::mat4;
};

#endif
