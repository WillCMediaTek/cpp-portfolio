/*
 * window.cpp
 *
 *  Created on: Apr 4, 2025
 *      Author: Willie clifton
 */

// window.cpp
#include "window.h"
#include <cstddef>
#include <iostream>

    // Create the window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    // Make the context current
    glfwMakeContextCurrent(window);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return NULL;
    }
    
    return window;
}

void destroyWindow(GLFWwindow* window) {
    glfwDestroyWindow(window);
    glfwTerminate();
}


