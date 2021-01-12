#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shader_program.h"
#include "shader.h"
#include "camera.h"
#include "cube.h"

enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attrib_IDs {vPosition = 0};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

Camera cam(glm::vec3(0.0f, 0.0f, -3.0f));


auto init(ShaderProgram &program, Shader &vertex, Shader &fragment) -> void
{
    static const glm::vec3 vertices[NumVertices] =
    {
        glm::vec3(-0.90, -0.90, 0.0f), // Triangle 1
        glm::vec3( 0.85, -0.90, 0.0f),
        glm::vec3(-0.90,  0.85, 0.0f),
        glm::vec3( 0.90, -0.85, 0.0f), // Triangle 2
        glm::vec3( 0.90,  0.90, 0.0f),
        glm::vec3(-0.85,  0.90, 0.0f),
    };

    glCreateVertexArrays(NumVAOs, VAOs);

    // Get the names (video card pointers)
    glCreateBuffers(NumBuffers, Buffers);
    // Alloc video memory and initialize it with vertices
    glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);


    program.set(vertex);
    program.set(fragment);

    program.compile();
    program.link();
    program.log();
    program.use();

    glBindVertexArray(VAOs[Triangles]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);

    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(vPosition);
}

auto display(ShaderProgram &program, Shader &vertex, Shader &fragment) -> void
{
    static const float black[] = {0.0f, 0.5f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, black);

    program.use();
    program.setUniform("view", cam.genViewMatrix());
    auto proj = glm::perspective(90.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    program.setUniform("projection", proj);

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

    ShaderProgram program;
    Shader vertex(GL_VERTEX_SHADER, "./src/shader.vert");
    Shader fragment(GL_FRAGMENT_SHADER, "./src/shader.frag");

    init(program, vertex, fragment);

    while (!glfwWindowShouldClose(window))
    {
        cam.think();
        display(program, vertex, fragment);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
