
#version 450 core

layout ( location = 0 ) in vec4 vPosition;

layout (location = 1) out vec3 position;

void main()
{
    position = vec3(1.0, 0.0, 0.0);
    gl_Position = vPosition;
}


