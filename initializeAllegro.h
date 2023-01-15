#ifndef PROJET_INITIALIZEALLEGRO_H
#define PROJET_INITIALIZEALLEGRO_H

#include "struct_macro.h"

int initializeAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33]);

int screenUpdate(int current_screen, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33], int current_char, int first);

int cleanUp(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33]);

#endif //PROJET_INITIALIZEALLEGRO_H
