#ifndef PROJET_ROUND_H
#define PROJET_ROUND_H

#include "struct_macro.h"
#include "initializeAllegro.h"
#include "printBoard.h"

void oneRound(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *Tiles[BOARDSIZE][BOARDSIZE], ALLEGRO_BITMAP *pawn_logo[4], Case board[BOARDSIZE][BOARDSIZE], Case *substituteValue, Pawn *character, char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS]);

#endif //PROJET_ROUND_H
