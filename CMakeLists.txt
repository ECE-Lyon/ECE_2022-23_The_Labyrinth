cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c struct_macro.h initializeAllegro.h initializeAllegro.c startGame.h startGame.c initializeBoard.h initializeBoard.c round.h round.c)
target_link_libraries(main ${ALLEGRO_LIBRARY})

target_link_libraries(main -lmingw32 -lallegro-5.0.10-monolith-md-debug)
