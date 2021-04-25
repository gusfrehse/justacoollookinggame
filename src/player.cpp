#include "player.h"
#include <camera.h>
#include <mesh.h>


auto Player::draw() -> void
{
    gun.draw();
}

auto Player::update() -> void
{}