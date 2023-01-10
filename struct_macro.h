#ifndef PROJET_STRUCT_MACRO_H
#define PROJET_STRUCT_MACRO_H

//Constants for the size of the game board and number of game pieces
#define NUM_MOVABLE_PIECES 33
#define NB_TREASURE_CARD 24
#define NB_CARD_BY_PERSON 6
#define MAX_LETTERS_WORDS 50
#define BOARDSIZE 7

typedef struct {char *boxtype, *treasure; int boxway, mobile, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;} Case;

typedef struct {char *boxtype; int treasure, boxway, character, x, y;} Pawn;

#endif //PROJET_STRUCT_MACRO_H
