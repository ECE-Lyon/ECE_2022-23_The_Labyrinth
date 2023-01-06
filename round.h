#ifndef PROJET_ROUND_H
#define PROJET_ROUND_H

#include "startGame.h"

#define NB_CARD_BY_PERSON 6
#define MAX_LETTERS_WORDS 50
#define BOARDSIDE 7

typedef struct {char *boxtype, *treasure; int boxway, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;} Case;

typedef struct {char *boxtype; int treasure, boxway, character, x, y;} Pawn;

int oneRound(Case board[BOARDSIDE][BOARDSIDE], char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS], Pawn character);

#endif //PROJET_ROUND_H
