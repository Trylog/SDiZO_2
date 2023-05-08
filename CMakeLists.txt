cmake_minimum_required(VERSION 3.24)
project(SDiZO_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDiZOrec main.cpp DisjoinedSets.cpp GraphList.h GraphList.cpp GraphMatrix.cpp PriorityQueue.cpp)
