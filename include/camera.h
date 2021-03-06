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

    glm::vec3 vel;
    glm::vec3 acc;
    glm::vec3 pos;
    glm::vec3 prev_pos;
    float yaw;
    float pitch;
    float roll;
    glm::vec3 dir;

    float acceleration;
    float max_speed;
    float friction_coef;
    double sensitivity;

    Camera(glm::vec3 position);
    
    auto translate(glm::vec3 where) -> void;

    auto move(glm::vec3 where) -> void;
    
    auto rotateX(float angle) -> void;
    auto rotateY(float angle) -> void;
    auto rotateZ(float angle) -> void;
    auto think() -> void;
    auto genViewMatrix() const -> glm::mat4;
};

#endif
