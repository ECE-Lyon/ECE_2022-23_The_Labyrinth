#ifndef PROJET_INITIALIZEBOARD_H
#define PROJET_INITIALIZEBOARD_H

#include "struct_macro.h"

char* initializeBoard(Pawn theEmpressPawn, Pawn theArchDruidPawn, Pawn theHauntedSeerPawn, Pawn theBrutalWandererPawn, Case board[BOARDSIZE][BOARDSIZE], Case substituteValue, char treasures[NB_TREASURE_CARD][MAX_LETTERS_WORDS]);

#endif //PROJET_INITIALIZEBOARD_H
