#ifndef G_CAMERA_H
#define G_CAMERA_H

#include <glm/vec3.hpp>
#include <glm/mat4.hpp>

class Camera
{
public:
    static const worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 up;
    glm::vec3 front;
    glm::vec3 right;

    glm::vec3 pos;
    glm::vec3 rot; // pitch, roll, yaw
    glm::vec3 dir;

    Camera(glm::vec3 position);
    
    auto translate(glm::vec3 where) -> void;
    auto rotate(glm::vec3 how) -> void;
    auto think() -> void;
    auto genViewMatrix() const -> glm::mat4;
}

#endif
