// main.cpp
#include "window.h"
#include <GLFW/glfw3.h>

void processInput(GLFWwindow *window);

int main() {
    // Create a window
    GLFWwindow* window = createWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Window");
    if (!window) {
        return -1;
    }
        	
    // Main loop
    while (!glfwWindowShouldClose(window)) {
      	// input
        // -----
        processInput(window);
        
        // Render here
        glClearColor(0.3f, 0.4f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Destroy the window
    destroyWindow(window);
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	// close window with traditional Alt+F4
    if (glfwGetKey(window, (GLFW_KEY_LEFT_ALT + GLFW_KEY_F4) )||(glfwGetKey)(window, (GLFW_KEY_RIGHT_ALT + GLFW_KEY_F4)) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}