cmake_minimum_required(VERSION 2.8)
project(nanoengine)

file(GLOB SOURCE
    "source/*.cpp"
    "source/*.h"
    "source/nodes/*.cpp"
    "source/nodes/*.h"
    )

add_library(lib_nanoengine ${SOURCE})

file(GLOB TESTS
    "tests/main.cpp"
    )

add_executable(test_nanoengine ${TESTS})
target_link_libraries(test_nanoengine lib_nanoengine)
