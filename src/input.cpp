#include <iostream>
#include <unordered_map>
#include <glm/vec3.hpp>

#include <GLFW/glfw3.h> 

#include "camera.h"
#include "input.h"


extern GLFWwindow* window;
extern Camera cam;
extern double deltaTime;

namespace Input {
    std::unordered_map<int, std::function<void()>> keyMapping = {
        {
            GLFW_KEY_W,
            []()
            {
                std::cout << "indo pra frente" << std::endl;
                cam.move((float) ( cam.speed) * cam.dir);
            }
        },
        {
            GLFW_KEY_S,
            []()
            {
                std::cout << "indo pra tras" << std::endl;
                cam.move((float) (- cam.speed) * cam.dir);
            }
        },
        {
            GLFW_KEY_D,
            []()
            {
                std::cout << "indo pra direita" << std::endl;
                cam.move((float) ( cam.speed) * cam.right);
            }
        },
        {
            GLFW_KEY_A,
            []()
            {
                std::cout << "indo pra esquerda" << std::endl;
                cam.move((float) (- cam.speed) * cam.right);
            }
        },
        {
            GLFW_KEY_SPACE,
            []()
            {
                cam.move((float) ( cam.speed) * Camera::worldUp);
            }
        },
        {
            GLFW_KEY_LEFT_SHIFT,
            []()
            {
                cam.move((float) (- cam.speed) * Camera::worldUp);
            }
        },
        {
            GLFW_KEY_ESCAPE,
            []()
            {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
        }
    };

    auto processKeyInput(int key, int scanCode, int action, int mods) -> void
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            if (Input::keyMapping.find(key) != Input::keyMapping.end()) // maybe one day change back to .contains()
            {
                Input::keyMapping[key]();
            }
        }
        else if (mods & GLFW_MOD_SHIFT)
        {
            // no key pressed but shift
            Input::keyMapping[GLFW_KEY_LEFT_SHIFT]();
        }
    }
    
    static double prevX = 0.0;
    static double prevY = 0.0;

    auto processMouseMoveInput(double x, double y) -> void
    {
        double deltaX = x - prevX;
        double deltaY = y - prevY;
        std::cout << "deltaX: " << deltaX << " deltaY: " << deltaY << std::endl;
        cam.rotate(Camera::worldUp, -deltaX * cam.sensitivity);
        cam.rotate(cam.right, -deltaY * cam.sensitivity);
        prevX = x;
        prevY = y;
    }
}
