cmake_minimum_required(VERSION 3.29)
project(books_manage_tool C)

set(CMAKE_C_STANDARD 11)

# Add the compiler flag to suppress the warning
add_compile_options(-Wno-implicit-function-declaration)

add_executable(books_manage_tool main.c)