cmake_minimum_required(VERSION 3.26)
project(Maze)

set(CMAKE_CXX_STANDARD 17)

add_executable(Maze main.cpp
        lib/GenericNode.hpp
        lib/IGenericStack.hpp
        lib/GenericStack.hpp
        lib/IGenericQueue.hpp
        lib/GenericQueue.hpp
        lib/Cell.hpp
        src/Maze.cpp
        lib/Maze.hpp)
