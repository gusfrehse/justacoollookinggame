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

enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attrib_IDs {vPosition = 0, vNormal};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

long long num_vertices;

glm::ivec2 window_size;

Camera cam(glm::vec3(0.0f, 0.0f, 3.0f));

double deltaTime = 0.0;

auto init(ShaderProgram &program, Shader &vertex, Shader &fragment) -> void
{
    Mesh mesh;
    mesh.open("teapot.obj");
    num_vertices = mesh.vertices.size();
    long long num_normals = mesh.normals.size();

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
    glCreateVertexArrays(NumVAOs, VAOs);

    // Get the names (video card pointers)
    glCreateBuffers(NumBuffers, Buffers);

    // Alloc video memory and initialize it with vertices
    glNamedBufferStorage(Buffers[ArrayBuffer],
			 (num_vertices + num_normals) * 3 * sizeof(float),
			 NULL,
			 GL_MAP_WRITE_BIT);

    float* vbo = (float *) glMapNamedBuffer(Buffers[ArrayBuffer], GL_WRITE_ONLY);
    std::cout << "vertices: " << num_vertices << " normals: " <<  num_normals << std::endl;
    std::memcpy(vbo, mesh.vertices.data(), num_vertices * 3 * sizeof(float));
    std::memcpy(vbo + num_vertices * 3, mesh.normals.data(), num_normals * 3 * sizeof(float));

    glUnmapNamedBuffer(Buffers[ArrayBuffer]);
    
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

    glVertexAttribPointer(vNormal, 3, GL_FLOAT, GL_FALSE, 0, (void*) (num_vertices * sizeof(glm::vec3)));
    glEnableVertexAttribArray(vNormal);

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

    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, num_vertices);
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
