cmake_minimum_required(VERSION 3.31)
project(NetoCheck)

set(CMAKE_CXX_STANDARD 20)

add_executable(NetoCheck
        catch_amalgamated.hpp
        firstTask/ListNode.cpp
#        firstTask/PositiveTests.cpp
        firstTask/NegativeTests.cpp
)
