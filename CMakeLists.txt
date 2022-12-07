cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c)
add_executable(afficherTableau affTabl.txt)
add_executable(affTabl2 affTabl2.c)