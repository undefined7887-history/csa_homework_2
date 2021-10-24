cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name
project(csa_homework_2 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(SOURCE_FILES
        src/main.cpp

        src/container.cpp
        src/container.h

        src/movie.cpp
        src/movie.h

        src/fiction.cpp
        src/fiction.h

        src/utils.h
        src/utils.cpp

        src/cartoon.cpp
        src/cartoon.h

        src/documentary.cpp
        src/documentary.h)

add_executable(csa_homework_2 ${SOURCE_FILES})
