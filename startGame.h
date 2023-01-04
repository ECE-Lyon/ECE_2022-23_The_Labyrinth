#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "boardCreation.h"
#include "round.h"
#include "initializeBoard.h"

#define NB_TREASURE_CARD 24
#define NB_CARD_BY_PERSON 6
#define MAX_LETTERS_WORDS 50
#define BOARDSIDE 7

typedef struct {char *boxtype, *treasure; int boxway, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;} Case;

typedef struct {char *boxtype; int treasure, boxway, character, x, y;} Pawn;

void startGame();

extern char treasureCardTheEmperess[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];
extern char treasureCardTheArchDruid[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];
extern char treasureCardTheHauntedSeer[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];
extern char treasureCardTheBrutalWanderer[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];

extern Case substituteValue;
extern Case board[BOARDSIDE][BOARDSIDE] = {{0}};

#endif //PROJET_STARTGAME_H