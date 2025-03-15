cmake_minimum_required(VERSION 3.14)

# Define the project name and version
project(Tourist VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the GLFW subdirectory (already uses CMake)
add_subdirectory(lib/glfw)

# Add the GLAD subdirectory
add_subdirectory(lib/glad) # Ensure lib/glad has a valid CMakeLists.txt

# Source files for the project
set(SOURCES
    src/main.cpp
    "src/Shader.cpp"
    "src/Shapes.cpp"
)

# Header files for the project
set(HEADERS
    "src/Shader.h"
    "src/Shapes.h"
)

# Create the executable for the project
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories for GLFW, GLAD, and the project itself
target_include_directories(${PROJECT_NAME} PUBLIC
    lib/glfw/include  # Include GLFW headers
    lib/glad/include  # Include GLAD headers
    ${CMAKE_SOURCE_DIR}/src/Include # Include project headers
)

# Link GLFW and GLAD to the executable
target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw   # Link GLFW
    glad   # Link GLAD
)

# Add OS-specific dependencies (e.g., OpenGL)
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} PUBLIC opengl32) # OpenGL for Windows
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} PUBLIC GL)       # OpenGL for Linux
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL)   # OpenGL for macOS
endif()

# Print a status message
message(STATUS "Project ${PROJECT_NAME} has been configured.")
