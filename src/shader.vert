#version 450 core

layout ( location = 0 ) in vec4 vPosition;

layout (location = 1) out vec3 position;

void main()
{
    position = 0.5 * (vPosition.xyz + vec3(1.0, 1.0, 0.0));
    gl_Position = vPosition;
}
