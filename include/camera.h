#ifndef G_CAMERA_H
#define G_CAMERA_H

#include <glm/vec3.hpp>
#include <glm/mat4.hpp>

class Camera
{
public:
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);

    glm::vec3 pos;
    glm::vec3 rot;

    Camera();
    
    auto translate(glm::vec3 where) -> void;
    auto rotate(glm::vec3 how) -> void;
    auto lookAt(glm::vec3 where) -> void;
    auto genViewMatrix() const -> glm::mat4;
}

#endif
