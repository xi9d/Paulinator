cmake_minimum_required(VERSION 3.14)

# Define the project name
project("Tourist")

# Add the GLFW subdirectory (already uses CMake)
add_subdirectory(lib/glfw)

# Add the GLAD subdirectory
add_subdirectory(lib/glad)   # This will process the CMakeLists.txt inside lib/glad/

# Create the executable for the project
add_executable(${PROJECT_NAME} src/main.cpp)

# Include directories for GLFW and GLAD
target_include_directories(${PROJECT_NAME} PUBLIC
    lib/glfw/include  # Include GLFW headers
    lib/glad/include   # Include GLAD headers
)

# Link GLFW and GLAD to your executable
target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw  # Link GLFW
    glad  # Link GLAD
)
