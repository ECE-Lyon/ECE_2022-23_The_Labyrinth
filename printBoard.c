#include <stdio.h>
#include "printBoard.h"

int printBoard(Case board[BOARDSIZE][BOARDSIZE]) {
    for(int i = 0; i < BOARDSIZE; i++) {
        for(int j = 0; j < BOARDSIZE; j++) {
            printf("/ %s %d - ", board[i][j].boxtype, board[i][j].boxway);

            if(board[i][j].theEmperess == 1) {
                printf("TE_ /");
            }
            else if(board[i][j].theArchDruid == 1) {
                printf("TAD /");
            }
            else if(board[i][j].theHauntedSeer == 1) {
                printf("THS /");
            }
            else if(board[i][j].theBrutalWanderer == 1) {
                printf("TBW /");
            }
            else  {
                printf("___ /");
            }

        }
        printf("\n");
    }
    return 0;
}
