cmake_minimum_required(VERSION 4.1)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(problema2
        main.cpp
        Student.cpp
        StudentCompare.cpp
        "../../lab-03/problema 1/Math.h"
        "../../lab-03/problema 1/Math.cpp"
        "../../lab-03/problema 1/main.cpp"
        "../../lab-03/problema 2/Canvas.h"
        "../../lab-03/problema 2/Canvas.cpp"
        "../../lab-03/problema 2/main.cpp"
)