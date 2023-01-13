#include <stdio.h>
#include "printBoard.h"

int printBoard(Case board[BOARDSIZE][BOARDSIZE]) {
    for(int i = 0; i < BOARDSIZE; i++) {
        for(int j = 0; j < BOARDSIZE; j++) {
            printf("/ %s %d /", board[i][j].boxtype, board[i][j].boxway);
        }
        printf("\n");
    }
}
