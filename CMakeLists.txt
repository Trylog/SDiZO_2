cmake_minimum_required(VERSION 3.24)
project(SDiZO_2)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SOURCE_FILES main.cpp)
add_executable(SDiZO_2 main.cpp DisjoinedSets.cpp GraphMatrix.cpp PriorityQueue.cpp GraphList.cpp MSTree.cpp TNode.h Edge.h Queue.cpp Queue.h)
