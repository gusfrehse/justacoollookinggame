#version 450 core

layout (location = 0) in vec4 vPosition;

out vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    position = vec3(1.0f, 0.0f, 0.0f);
    gl_Position = projection * view * model * vPosition;
}
