#version 450 core

in vec3 position;

out vec4 fColor;

void main()
{
    fColor = vec4(position, 1.0);
}
