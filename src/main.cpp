#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shader_program.h"
#include "shader.h"

enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attrib_IDs {vPosition = 0};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;


void init(void)
{
    static const GLfloat vertices[NumVertices][2] =
    {
        {-0.90, -0.90}, // Triangle 1
        { 0.85, -0.90},
        {-0.90,  0.85},
        { 0.90, -0.85}, // Triangle 2
        { 0.90,  0.90},
        {-0.85,  0.90},
    };
    // Get the names (video card pointers)
    glCreateBuffers(NumBuffers, Buffers);
    // Alloc video memory and initialize it with vertices
    glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);

    auto program = ShaderProgram();
    auto vertex = Shader(GL_VERTEX_SHADER, "./src/vert.glsl");
    auto fragment = Shader(GL_FRAGMENT_SHADER, "./src/frag.glsl");

    program.set(vertex);
    program.set(fragment);

    program.compile();
    program.link();
    //program.log();
}

int main(void)
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "Triangles", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (gl3wInit())
    {
        std::cerr << "gl3wInit() failed" << std::endl;
    
    }

    init();

    while (!glfwWindowShouldClose(window))
    {
        // display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
