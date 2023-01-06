#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "initializeBoard.h"
#include "round.h"

//Constants for the size of the game board and number of game pieces
#define NUM_STATIC_PIECES 16
#define NUM_MOVABLE_PIECES 33
#define NB_TREASURE_CARD 24
#define NB_CARD_BY_PERSON 6
#define MAX_LETTERS_WORDS 50
#define BOARDSIDE 7

typedef struct {char *boxtype, *treasure; int boxway, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;} Case;

typedef struct {char *boxtype; int treasure, boxway, character, x, y;} Pawn;

void startGame();

#endif //PROJET_STARTGAME_H