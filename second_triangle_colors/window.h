/*
 * window.h
 *
 *  Created on: Apr 4, 2025
 *      Author: willie clifton
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// window setting declaration
extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

GLFWwindow* createWindow(int width, int height, const char* title);
void destroyWindow(GLFWwindow* window);

#endif /* WINDOW_H_ */