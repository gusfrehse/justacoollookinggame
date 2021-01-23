#include <iostream>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "input.h"
#include "callbacks.h"

// from main.cpp
extern GLFWwindow* window;

auto setCallbacks() -> void
{
    glfwSetErrorCallback(error_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
    glfwSetKeyCallback(window, process_key_callback);
}

auto framebuffer_resize_callback(GLFWwindow* window, int width, int height) -> void
{
    glViewport(0, 0, width, height);
}

auto error_callback(int error, const char *description) -> void
{
    std::cerr << "GLFW Error:\n" << description << std::endl;
}

auto process_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) -> void
{
    Input::processInput(key, scancode, action, mods);


}

