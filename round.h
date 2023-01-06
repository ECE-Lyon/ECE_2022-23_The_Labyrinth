#ifndef PROJET_ROUND_H
#define PROJET_ROUND_H

#include "startGame.h"

#define NB_CARD_BY_PERSON 6
#define MAX_LETTERS_WORDS 50

int oneRound(Case board[BOARDSIDE][BOARDSIDE], char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS], Pawn character);

#endif //PROJET_ROUND_H
