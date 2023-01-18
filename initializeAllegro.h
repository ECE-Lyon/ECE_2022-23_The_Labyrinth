#ifndef PROJET_INITIALIZEALLEGRO_H
#define PROJET_INITIALIZEALLEGRO_H

#include "struct_macro.h"

int initializeAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4]);

void screenUpdate(int current_screen, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *Tiles[BOARDSIZE][BOARDSIZE], Case board[BOARDSIZE][BOARDSIZE], int current_char, int first);

int cleanUp(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *Tiles[BOARDSIZE][BOARDSIZE]);

#endif //PROJET_INITIALIZEALLEGRO_H
