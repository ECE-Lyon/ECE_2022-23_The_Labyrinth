#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "struct_macro.h"
#include "initializeAllegro.h"
#include "printBoard.h"
#include "initializeBoard.h"
#include "round.h"

int startGame(ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16]);

#endif //PROJET_STARTGAME_H