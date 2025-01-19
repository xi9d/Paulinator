#include <iostream>
#include <glad/glad.h>  // for OpenGL graphics API
#include <GLFW/glfw3.h> // for GLFW window handling
#include <sstream>       // for stringstream
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
        ss << "Paulinator.exe - FPS: " << fps;
        glfwSetWindowTitle(window, ss.str().c_str());  // Update window title with FPS
    }
}

int main() {
    GLFWwindow *window;

    // Initialize GLFW
    if (!glfwInit()) {
        cout << "GLFW initialization failed" << endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(800, 450, "Paulinator.exe", nullptr, nullptr);
    if (!window) {
        cout << "Window creation failed" << endl;
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "GLAD initialization failed" << endl;
        glfwTerminate();
        return -1;
    }

    // Enable vsync
    glfwSwapInterval(1);

    // Variables for FPS calculation
    double lastTime = glfwGetTime();
    int frameCount = 0;

    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events
        glfwPollEvents();

        // Clear the screen with a dark gray background
        glClearColor(0.07f, 0.07f, 0.07f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Display the FPS on the window title
        displayFPS(window, lastTime, frameCount);

        // Swap buffers to update the window
        glfwSwapBuffers(window);
    }

    // Terminate GLFW when done
    glfwTerminate();
    return 0;
}
