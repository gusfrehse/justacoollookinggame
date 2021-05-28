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
    glm::mat4 gun_rot_mat = glm::mat4(glm::mat3(cam->right, cam->up, cam->dir));
    // glm::mat4 gun_scale_mat = glm::scale(gun_rot_mat, gun_scale);
    glm::mat4 gun_translate_mat = glm::translate(gun_rot_mat, gun_offset + cam->pos);//cam->right + cam->pos);
    gun_model = gun_translate_mat; 
}