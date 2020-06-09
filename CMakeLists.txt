cmake_minimum_required(VERSION 3.10)

# set the project name
project(Leaf)

# set minimum C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLAD_SOURCES "leaf/src/glad/glad.c")
set(SRC_SOURCES "leaf/src/application.cpp" "leaf/src/ShaderProgram.h"
"leaf/src/ShaderProgram.cpp")
set(STB_SOURCES "leaf/src/stb/stb_image.h")

add_subdirectory(include/GLFW)

# add GLFW and glad to configuration
include_directories(include/GLFW/include)
include_directories(include)
include_directories(include/glm)

add_executable(Leaf ${GLAD_SOURCES} ${SRC_SOURCES} ${STB_SOURCES})

FILE(COPY Leaf/assets/soil.jpg DESTINATION "${CMAKE_BINARY_DIR}/Leaf/assets")

# link necessary files from GLFW
target_link_libraries(Leaf glfw ${GLFW_LIBRARIES})


