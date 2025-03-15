#include <iostream>
#include <glad/glad.h>  // for OpenGL graphics API
#include <GLFW/glfw3.h> // for GLFW window handling
#include <sstream>       // for stringstream
#include "Shader.h";
<<<<<<< HEAD
#include "Triangle.h";
#include "Circle.h"
=======
#include "Shapes.h";
>>>>>>> 0e431ed54ce4a2a50e35ccce3ecb9077ab1d0541
using namespace std;

// Function to display FPS on the screen
void displayFPS(GLFWwindow* window, double& lastTime, int& frameCount) {
    double currentTime = glfwGetTime();  // Get the current time
    frameCount++;

    // If one second has passed, update the FPS counter and display it
    if (currentTime - lastTime >= 1.0) {
        int fps = frameCount;  // FPS is the number of frames in 1 second
        frameCount = 0;         // Reset frame count for the next second
        lastTime = currentTime; // Reset the last time

        // Display FPS in the window title 
        stringstream ss;
<<<<<<< HEAD
        ss << "Tourist 3" << fps;
=======
        ss << "Tourist " << fps;
>>>>>>> 0e431ed54ce4a2a50e35ccce3ecb9077ab1d0541
        glfwSetWindowTitle(window, ss.str().c_str());  // Update window title with FPS
    }
}

// a simple shape displayed on the screen
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

}

int main() {
    GLFWwindow *window;

    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(800, 450, "Tourist", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return -1;
    }

    // Enable vsync
    glfwSwapInterval(1);    

    // Variables for FPS calculation
    double lastTime = glfwGetTime();
    int frameCount = 0;
    // create an instance for the shader windows
    Shader shader("Shaders/basic.vert", "Shaders/basic.frag");
    Triangle triangle;
    Circle circle;
    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        
        // Clear the screen with a dark gray background
        glClearColor(0.07f, 0.07f, 0.07f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        triangle.draw();
        circle.draw();
        // Display the FPS on the window title
        displayFPS(window, lastTime, frameCount);

        // Swap buffers to update the window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW when done
    glfwTerminate();
    return 0;
}
