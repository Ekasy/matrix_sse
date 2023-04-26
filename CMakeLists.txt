cmake_minimum_required(VERSION 3.12.3)

project(matrix VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(
    -Werror
    -Wall
    -march=native
)

add_executable(matrix   main.cpp
)

add_subdirectory(lib)
add_subdirectory(util)

target_link_libraries(matrix PUBLIC lib
                                    util)

target_include_directories(matrix PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_BINARY_DIR}/lib"
    "${PROJECT_BINARY_DIR}/util"
)
