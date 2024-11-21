# CMakeLists.txt inside lib/glad/

# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.14)

# Create a GLAD static library
add_library(glad STATIC src/glad.c)   # Add the GLAD source file (make sure the path is correct)

# Set include directories for GLAD
target_include_directories(glad PUBLIC include)

# Ensure GLAD is built and its include paths are available
