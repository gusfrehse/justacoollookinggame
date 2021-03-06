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
            GLFW_KEY_ESCAPE,
            []()
            {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
        }
    };

    std::unordered_map<int, std::function<void()>> keyQuickMapping = {
        {
            GLFW_KEY_W,
            []()
            {
                auto direction = cam.dir;
                direction.y = 0;
                direction = glm::normalize(direction);
                cam.move((cam.acceleration) * (float) deltaTime * direction);
            }
        },
        {
            GLFW_KEY_S,
            []()
            {
                auto direction = cam.dir;
                direction.y = 0;
                direction = glm::normalize(direction);
                cam.move((-cam.acceleration) * (float) deltaTime * direction);
            }
        },
        {
            GLFW_KEY_D,
            []()
            {
                cam.move((cam.acceleration) * (float) deltaTime * cam.right);
            }
        },
        {
            GLFW_KEY_A,
            []()
            {
                cam.move((-cam.acceleration) * (float) deltaTime * cam.right);
            }
        },
        {
            GLFW_KEY_SPACE,
            []()
            {
                cam.move((cam.acceleration) * (float) deltaTime * Camera::worldUp);
            }
        },
        {
            GLFW_KEY_LEFT_SHIFT,
            []()
            {
                cam.move((-cam.acceleration) * (float) deltaTime * Camera::worldUp);
            }
        },
        {
            GLFW_KEY_J,
            []()
            {
                cam.friction_coef -= 0.01f;
                std::cout << "friction_coef is now " << cam.friction_coef << std::endl;

            }
        },
        {
            GLFW_KEY_K,
            []()
            {
                cam.friction_coef += 0.01f;
                std::cout << "friction_coef is now " << cam.friction_coef << std::endl;
            }
        }
    };

    auto processKeyInput(int key, int scanCode, int action, int mods) -> void
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            if (Input::keyMapping.find(key) != Input::keyMapping.end())
            {
                Input::keyMapping[key]();
            }
        }
    }
    
    auto processQuickKeyInput() -> void
    {
        for (auto&& [k, f] : keyQuickMapping)
        {
            int state = glfwGetKey(window, k);
            if (state == GLFW_PRESS || state == GLFW_REPEAT)
                f(); 
        }
    }


    static double prevX = 0.0;
    static double prevY = 0.0;

    auto processMouseInput() -> void
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        double deltaX = x - prevX;
        double deltaY = y - prevY;

        cam.rotateY( deltaX * cam.sensitivity * deltaTime);
        cam.rotateX(-deltaY * cam.sensitivity * deltaTime);
        prevX = x;
        prevY = y;
    }
}
