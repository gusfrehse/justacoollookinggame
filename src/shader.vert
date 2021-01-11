#version 450 core

layout (location = 0) in vec4 vPosition;

layout (location = 1) out vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    position = 0.5 * (vPosition.xyz + vec3(1.0, 1.0, 0.0));
    gl_Position = projection * model * view * vPosition;
}
