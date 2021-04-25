#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include <camera.h>
#include <mesh.h>


class Player
{
    Camera& cam;
    Mesh& gun;
    char health;
    char ammo;

    auto draw() -> void;
    auto update() -> void;
};
#endif  