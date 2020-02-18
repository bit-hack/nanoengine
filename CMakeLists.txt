cmake_minimum_required(VERSION 2.8)
project(nanoengine)

file(GLOB SOURCE
    "source/*.cpp"
    "source/*.h"
    "source/nodes/*.cpp"
    "source/nodes/*.h"
    )

add_executable(nanoengine ${SOURCE})
