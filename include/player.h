#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include <camera.h>
#include <mesh.h>
#include <glm/mat4x4.hpp>


class Player
{
public:
    Camera* cam;
    Mesh* gun;
    glm::vec3 gun_offset = glm::vec3(0.0, 1.0, 0.0);
    glm::vec3 gun_scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::mat4 gun_model = glm::mat4(1.0f);
    glm::vec3 gun_color = glm::vec3(0.145f, 0.015f, 0.662f);
    char health = 100;
    char ammo = 100;

    auto draw(glm::mat4 view, glm::mat4 proj) -> void;
    auto update() -> void;
};
#endif  