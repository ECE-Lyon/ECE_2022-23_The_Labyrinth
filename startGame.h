#ifndef PROJET_STARTGAME_H
#define PROJET_STARTGAME_H

#include "struct_macro.h"
#include "initializeAllegro.h"
#include "printBoard.h"
#include "initializeBoard.h"
#include "round.h"

void startGame(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *Tiles[BOARDSIZE][BOARDSIZE], Case board[BOARDSIZE][BOARDSIZE]);

#endif //PROJET_STARTGAME_H