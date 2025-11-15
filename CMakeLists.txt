cmake_minimum_required(VERSION 3.31)
project(NetoCheck)

set(CMAKE_CXX_STANDARD 20)

add_executable(NetoCheck
        dependencies/catch_amalgamated.hpp
        dependencies/catch_amalgamated.cpp

        ListNode.cpp
        Tests.cpp
)
