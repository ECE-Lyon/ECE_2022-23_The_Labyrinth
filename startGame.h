#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "boardCreation.h"
#include "round.h"

#define nbTreasureCard 24
#define nbCardByPerson 6
#define maxLettersWords 50

typedef struct {int typeCase, orientationCase, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer; char tresor;} Case;

void startGame();

#endif //PROJET_STARTGAME_H