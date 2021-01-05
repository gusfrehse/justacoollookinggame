#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shader_program.h"
#include "shader.h"
#include "cube.h"

enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attrib_IDs {vPosition = 0};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;


auto init(void) -> void
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

    glCreateVertexArrays(NumVAOs, VAOs);

    // Get the names (video card pointers)
    glCreateBuffers(NumBuffers, Buffers);
    // Alloc video memory and initialize it with vertices
    glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);

    auto program = ShaderProgram();
    auto vertex = Shader(GL_VERTEX_SHADER, "./src/shader.vert");
    auto fragment = Shader(GL_FRAGMENT_SHADER, "./src/shader.frag");

    program.set(vertex);
    program.set(fragment);

    program.compile();
    program.link();
    program.log();
    program.use();

    glBindVertexArray(VAOs[Triangles]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);

    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(vPosition);
}

auto display(void) -> void
{
    static const float black[] = {0.0f, 0.0f, 0.0f, 0.0f};
    glClearBufferfv(GL_COLOR, 0, black);

    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);

}

static void error_callback(int error, const char *description)
{
    std::cerr << "GLFW Error:\n" << description << std::endl;;
}

auto main(void) -> int
{ 
    if (!glfwInit())
    {
        std::cerr << "Could not init glfw (glfwInit())" << std::endl;
        return 1;
    }
    glfwSetErrorCallback(error_callback);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Triangles", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (gl3wInit())
    {
        std::cerr << "gl3wInit() failed" << std::endl;
    
    }

    init();

    while (!glfwWindowShouldClose(window))
    {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
