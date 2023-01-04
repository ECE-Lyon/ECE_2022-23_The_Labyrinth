#ifndef PROJET_INITIALIZEBOARD_H
#define PROJET_INITIALIZEBOARD_H

#include "startGame.h"
//#include "resetLABressources.c"

//Constants for the size of the game board and number of game pieces
#define NUM_STATIC_PIECES 16
#define NUM_MOVABLE_PIECES 33

// Struct to represent a game piece with x and y coordinates
typedef struct {
    int x;
    int y;
    int number;
} GamePiece;

void initializeBoard();

#endif //PROJET_INITIALIZEBOARD_H
