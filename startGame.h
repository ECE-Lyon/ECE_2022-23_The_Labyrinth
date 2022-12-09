#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "boardCreation.h"
#include "round.h"

#define nbTreasureCard 24
#define nbCardByPerson 6
#define maxLettersWords 50

int player = 0;
int nbPlayer = 0;
int theEmperess = 0, theArchDruid = 0, theHauntedSeer = 0, theBrutalWanderer = 0;
char treasureCardTheEmperess[nbCardByPerson][maxLettersWords], treasureCardTheArchDruid[nbCardByPerson][maxLettersWords],
treasureCardTheHauntedSeer[nbCardByPerson][maxLettersWords], treasureCardTheBrutalWanderer[nbCardByPerson][maxLettersWords];
char treasuresCard[24][maxLettersWords] = {"chauve souris", "épée", "dragon", "génie", "livre", "hiboux",
                          "papillon", "clés", "scarabé", "champignon", "princesse", "diadem",
                          "géant", "crane", "araignée", "couronne", "chandelier", "carte",
                          "trésor", "serpent", "statut", "or", "souris", "fantome"};

typedef struct {int typeCase, orientationCase, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer; char tresor;} Case;

void startGame();

#endif //PROJET_STARTGAME_H