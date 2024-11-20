#include <iostream>
#include <GLFW/glfw3.h>

int main() {
    GLFWwindow *window;

    if(!glfwInit){
      std::cout << "GLFW initialized Failed" << std::endl;
      return -1;
    }

     window = glfwCreateWindow(800, 450, "Paulinator in action", 0, 0);

   
     if (!window)
     {
      std::cout << "Window wasnt created" << std::endl;
      return -1;
     }
      glfwMakeContextCurrent(window);

      while (!glfwWindowShouldClose(window))
      {
        glfwPollEvents();
        glfwSwapBuffers(window);
      }
      glfwTerminate();
   return 0;
}