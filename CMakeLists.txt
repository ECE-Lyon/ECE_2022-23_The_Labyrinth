cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c startGame.h startGame.c round.h round.c boardCreation.h boardCreation.c)
add_executable(affTabl affTabl2.c)