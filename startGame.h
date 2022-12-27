#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "boardCreation.h"
#include "round.h"

#define nbTreasureCard 24
#define nbCardByPerson 6
#define maxLettersWords 50
#define nbTilesBoard 16
#define  nbTilesLabyrinthe 34
#define BOARDSIDE 7

typedef struct {char boxtype, treasure; int boxway, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;} Case;

typedef struct {char boxtype, treasure; int boxway, character, x, y;} Pawn;

void startGame();

#endif //PROJET_STARTGAME_H