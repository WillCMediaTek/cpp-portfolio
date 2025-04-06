// main.cpp
#include "window.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.7f, 0.1f, 1.0f);\n"
    "}\n\0";

int main() {
    // Create a window
    GLFWwindow* window = createWindow(SCR_WIDTH , SCR_HEIGHT,"Second Triangle");
    if (!window) {
        return -1;
    }
    // Make the context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }
	
	// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);    
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	//check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout<< "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<infoLog << std::endl;
	}
	  
	// fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout<< "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<infoLog << std::endl;
	}
	
	//link shaders
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout<< "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	// Setup vertex data
	float firstTriangle[] = {
		-0.7f, -0.6f, 0.0f, // left
		0.0f, -0.6f, 0.0f, // right
		-0.35f, 0.3f, 0.0f // top
	};
	
	float secondTriangle[] = {
		0.7f, -0.6f, 0.0f, // left
		0.0f, -0.6f, -0.0f, // right
		0.35f, 0.3f, 0.0f // top
	};

	//create a 1 dimensional array for Vertex buffer Objects and VertexArrayObjects
	unsigned int VBOs[2], VAOs[2];
	// tell GL how many vertex arrays to generate
	glGenVertexArrays(2, VAOs);
	// the GL to set up two buffers for vertexBufferObjects
	glGenBuffers(2, VBOs);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	
	//triangle zero
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//triangle one
	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	//glBindVertexArray(0); 
 
	// uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClearColor(0.3f, 0.4f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
						
		// Use the shader program
		glUseProgram(shaderProgram);
			
		// draw our first Triangle
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		// draw our second Triangle
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	
        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    //optional: de-allocate all resources once they've done their job
    glDeleteVertexArrays(1, VAOs);
	glDeleteBuffers(1, VBOs);
	glDeleteProgram(shaderProgram);
	
     glfwTerminate();
    return 0;
}