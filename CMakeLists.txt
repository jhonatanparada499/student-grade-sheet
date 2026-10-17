# CMakeLists.txt
#
# Inspiration: https://keasigmadelta.com/blog/cmake-tutorial-getting-started/#writing-your
#
# Def Cmake version
cmake_minimum_required(VERSION 3.24)

# Set project's name
project(student-grade-sheet)

# Compiles using C++20 standard (-std=C++20)
# falls back to older std if not found
# set(CMAKE_CXX_STANDARD 20)

# Our Project files
set(SOURCE_FILES
    src/main.cpp
    src/Student.cpp
    src/Course.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
