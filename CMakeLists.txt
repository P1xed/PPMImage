cmake_minimum_required(VERSION 3.10)

project(PPMImage)

find_package(SDL3 CONFIG REQUIRED)

add_library(PPMImage STATIC
    PPMImage.cpp
    PPMImage.h
        example/test2/main.cpp
)

target_link_libraries(PPMImage PRIVATE SDL3::SDL3)

target_include_directories(PPMImage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

project(test1)

add_executable(test1
        example/test1/main.cpp
)

target_link_libraries(test1 PPMImage)

project(test2)

add_executable(test2
        example/test2/main.cpp
)

target_link_libraries(test2 PPMImage)
