#ifndef PROJET_STRUCT_MACRO_H
#define PROJET_STRUCT_MACRO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "startGame.h"

//Constants for Allegro
#define NB_IMAGES 21
#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

//Constants for C
#define NUM_MOVABLE_PIECES 33
#define NB_TREASURE_CARD 24
#define NB_CARD_BY_PERSON 6
#define MAX_LETTERS_WORDS 50
#define BOARDSIZE 7

typedef struct {char *boxtype, *treasure; int boxway, mobile, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;} Case;

typedef struct {char *boxtype; int treasure, boxway, character, x, y;} Pawn;

#endif //PROJET_STRUCT_MACRO_H
