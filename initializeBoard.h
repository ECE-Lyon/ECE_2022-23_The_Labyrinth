#ifndef PROJET_INITIALIZEBOARD_H
#define PROJET_INITIALIZEBOARD_H

#include "startGame.h"
//#include "resetLABressources.c"

// Struct to represent a game piece with x and y coordinates
typedef struct {
    int x;
    int y;
    int number;
} GamePiece;

void initializeBoard();

#endif //PROJET_INITIALIZEBOARD_H
