#ifndef G_CALLBACKS_H
#define G_CALLBACKS_H

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

auto setCallbacks() -> void;

auto framebuffer_resize_callback(GLFWwindow* window, int width, int height) -> void;

auto error_callback(int error, const char *description) -> void;

#endif
