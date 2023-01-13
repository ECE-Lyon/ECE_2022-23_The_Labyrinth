#ifndef PROJET_ROUND_H
#define PROJET_ROUND_H

#include "struct_macro.h"
#include "initializeAllegro.h"
#include "printBoard.h"

int oneRound(Case board[BOARDSIZE][BOARDSIZE], Case substituteValue, Pawn character, char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS]);

#endif //PROJET_ROUND_H
