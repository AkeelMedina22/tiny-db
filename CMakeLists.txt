cmake_minimum_required(VERSION 3.10)

# Set the project name
project(tiny-db)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add an executable target
add_executable(tiny-db ${SOURCES})