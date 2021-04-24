#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstring>

#include "shader_program.h"
#include "shader.h"
#include "camera.h"
#include "cube.h"
#include "callbacks.h"
#include "input.h"
#include "mesh.h"

GLFWwindow* window;

Mesh mesh;

glm::ivec2 window_size;

Camera cam(glm::vec3(0.0f, 0.0f, 3.0f));

double deltaTime = 0.0;

auto init(ShaderProgram &program, Shader &vertex, Shader &fragment) -> void
{
    mesh.open("assets/gun.obj");
    mesh.gen_vao();

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
    program.set(vertex);
    program.set(fragment);

    program.compile();
    program.link();
    program.log();
    program.use();
}

auto display(ShaderProgram &program, Shader &vertex, Shader &fragment) -> void
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program.use();
    program.setUniform("view", cam.genViewMatrix());
    auto proj = glm::perspective(glm::radians(90.0f),
				 ((float) window_size.x) / ((float)window_size.y),
				 0.1f,
				 100.0f);
    program.setUniform("projection", proj);
    auto model = glm::mat4x4(1.0f);
    program.setUniform("model", model);

    glBindVertexArray(mesh.vao);
    glDrawArrays(GL_TRIANGLES, 0, mesh.vertices.size());
}


auto main(void) -> int
{ 
    if (!glfwInit())
    {
        std::cerr << "Could not init glfw (glfwInit())" << std::endl;
        return 1;
    }

    window_size.x = 640;
    window_size.y = 480;
    window = glfwCreateWindow(window_size.x, window_size.y, "Triangles", NULL, NULL);
    glfwSwapInterval(1);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (glfwRawMouseMotionSupported())
    {
        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    }
    setCallbacks();
    glfwMakeContextCurrent(window);
    if (gl3wInit())
    {
        std::cerr << "gl3wInit() failed" << std::endl;
    
    }

    ShaderProgram program;
    Shader vertex(GL_VERTEX_SHADER, "./src/shader.vert");
    Shader fragment(GL_FRAGMENT_SHADER, "./src/shader.frag");

    init(program, vertex, fragment);

    auto prevTime = glfwGetTime();
    auto nowTime  = glfwGetTime();
    deltaTime = glfwGetTime();
    while (!glfwWindowShouldClose(window))
    {
	Input::processQuickKeyInput();
        Input::processMouseInput();
        cam.think();
        display(program, vertex, fragment);
        glfwSwapBuffers(window);
        glfwPollEvents();

        prevTime = nowTime;
        nowTime = glfwGetTime();
        deltaTime = nowTime - prevTime;
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
