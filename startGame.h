#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "boardCreation.h"
#include "round.h"

#define nbTreasureCard 24
#define nbCardByPerson 6
#define maxLettersWords 50
#define BOARDSIDE 7

typedef struct {char *boxtype, *treasure; int boxway, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;} Case;

typedef struct {char *boxtype; int treasure, boxway, character, x, y;} Pawn;

void startGame();

extern char treasureCardTheEmperess[nbCardByPerson][maxLettersWords];
extern char treasureCardTheArchDruid[nbCardByPerson][maxLettersWords];
extern char treasureCardTheHauntedSeer[nbCardByPerson][maxLettersWords];
extern char treasureCardTheBrutalWanderer[nbCardByPerson][maxLettersWords];

extern Case substituteValue;
extern Case board[BOARDSIDE][BOARDSIDE] = {{0}};

#endif //PROJET_STARTGAME_H