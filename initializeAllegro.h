#ifndef PROJET_INITIALIZEALLEGRO_H
#define PROJET_INITIALIZEALLEGRO_H

#include "struct_macro.h"

int initializeAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT_QUEUE *charEventQueue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16]);

int screenUpdate(int current_screen, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16]);

void cleanUp(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT_QUEUE *charEventQueue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16]);

#endif //PROJET_INITIALIZEALLEGRO_H
