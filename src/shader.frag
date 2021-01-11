#version 450 core
layout(location = 0) out vec4 fColor;

layout (location = 1) in vec3 position;

void main()
{
    fColor = vec4(2*position, 1.0);
}
