#version 450 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vNormal;

out vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    color = (vNormal + vec3(1.0, 1.0, 1.0f)) / 2.0;
    vec4 pos = vec4(vPosition, 1.0);
    gl_Position = projection * view * model * pos;
}
