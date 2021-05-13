#include "player.h"
#include "shader_program.h"
#include <camera.h>
#include <mesh.h>

extern ShaderProgram basic_color;

auto Player::draw(glm::mat4 view, glm::mat4 proj) -> void
{
    basic_color.use();
    basic_color.setUniform("color", gun_color);
    basic_color.setUniform("model", gun_model);
    basic_color.setUniform("view", view);
    basic_color.setUniform("projection", proj);
    (*gun).draw();

}

auto Player::update() -> void
{
    gun_model = glm::translate(
                    glm::scale(
                        glm::mat4(1.0f), gun_scale),
                    gun_offset + (*cam).pos);
}