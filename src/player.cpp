#include "player.h"
#include "shader_program.h"
#include "camera.h"
#include "mesh.h"


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
    glm::mat4 gun_rot_mat = glm::mat4(glm::mat3(cam->dir, cam->up, -cam->right));
    
    glm::vec3 gun_translation = cam->right + cam->pos;
    glm::mat4 gun_tra_mat = glm::mat4(1.0f);
    gun_tra_mat[3] = glm::vec4(gun_translation, 1.0f);

    gun_model = gun_tra_mat * gun_rot_mat;
}