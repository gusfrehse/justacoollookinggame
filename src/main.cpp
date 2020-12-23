#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>

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

    
}

int main(void)
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "Triangles", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (gl3wInit())
    {
        std::cout << "gl3wInit() failed" << std::endl;
    
    }

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
