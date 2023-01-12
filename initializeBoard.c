#include <stdlib.h>
#include "initializeBoard.h"

void initializeBoard(Pawn theEmpressPawn, Pawn theArchDruidPawn, Pawn theHauntedSeerPawn, Pawn theBrutalWandererPawn, Case board[BOARDSIZE][BOARDSIZE], Case substituteValue, char treasures[NB_TREASURE_CARD][MAX_LETTERS_WORDS]) {

    //----CORNERS----//
    board[0][0].boxtype = "L";
    board[0][0].boxway = 1;
    theEmpressPawn.boxtype = "L";
    theEmpressPawn.boxway = 1;
    theEmpressPawn.x = 0;
    theEmpressPawn.y = 0;
    board[BOARDSIZE - 1][0].boxtype = "L";
    board[BOARDSIZE - 1][0].boxway = 2;
    theArchDruidPawn.boxtype = "L";
    theArchDruidPawn.boxway = 2;
    theArchDruidPawn.x = BOARDSIZE - 1;
    theArchDruidPawn.y = 0;
    board[0][BOARDSIZE - 1].boxtype = "L";
    board[0][BOARDSIZE - 1].boxway = 0;
    theHauntedSeerPawn.boxtype = "L";
    theHauntedSeerPawn.boxway = 0;
    theHauntedSeerPawn.x = 0;
    theHauntedSeerPawn.y = BOARDSIZE - 1;
    board[BOARDSIZE - 1][BOARDSIZE - 1].boxtype = "L";
    board[BOARDSIZE - 1][BOARDSIZE - 1].boxway = 3;
    theBrutalWandererPawn.boxtype = "L";
    theBrutalWandererPawn.boxway = 3;
    theBrutalWandererPawn.x = BOARDSIZE - 1;
    theBrutalWandererPawn.y = BOARDSIZE - 1;


    //----OUTLINE----//
    for(int line = 2; line < BOARDSIZE - 2; line += 2) {
        board[line][0].boxtype = "T";
        board[line][0].boxway = 0;
    }
    board[2][0].treasure = treasures[12];
    board[4][0].treasure = treasures[13];
    for(int line = 2; line < BOARDSIZE - 2; line += 2) {
        board[line][BOARDSIZE - 1].boxtype = "T";
        board[line][BOARDSIZE - 1].boxway = 2;
    }
    board[2][BOARDSIZE - 1].treasure = treasures[22];
    board[4][BOARDSIZE - 1].treasure = treasures[23];
    for(int column = 2; column < BOARDSIZE - 2; column += 2) {
        board[0][column].boxtype = "T";
        board[0][column].boxway = 3;
    }
    board[0][2].treasure = treasures[14];
    board[0][4].treasure = treasures[18];
    for(int column = 2; column < BOARDSIZE - 2; column += 2) {
        board[BOARDSIZE - 1][column].boxtype = "T";
        board[BOARDSIZE - 1][column].boxway = 1;
    }
    board[BOARDSIZE - 1][2].treasure = treasures[17];
    board[BOARDSIZE - 1][4].treasure = treasures[21];


    //----CENTER----//
    board[2][2].boxtype = "T";
    board[2][2].boxway = 3;
    board[2][2].treasure = treasures[15];
    board[BOARDSIZE - 3][2].boxtype = "T";
    board[BOARDSIZE - 3][2].boxway = 0;
    board[BOARDSIZE - 3][2].treasure = treasures[16];
    board[2][BOARDSIZE - 3].boxtype = "T";
    board[2][BOARDSIZE - 3].boxway = 1;
    board[2][BOARDSIZE - 3].treasure = treasures[19];
    board[BOARDSIZE - 3][BOARDSIZE - 3].boxtype = "T";
    board[BOARDSIZE - 3][BOARDSIZE - 3].boxway = 2;
    board[BOARDSIZE - 3][BOARDSIZE - 3].treasure = treasures[20];


    //----CREATION MOBILES----//
    for(int i = 0; i < BOARDSIZE - 1; i++) {
        board[i][1].boxway = rand() % 3;
        board[i][1].mobile = 1;
    }
    for(int i = 0; i < BOARDSIZE - 1; i++) {
        board[i][3].boxway = rand() % 3;
        board[i][3].mobile = 1;
    }
    for(int i = 0; i < BOARDSIZE - 1; i++) {
        board[i][5].boxway = rand() % 3;
        board[i][5].mobile = 1;
    }
    board[1][0].boxtype = "T";
    board[1][0].boxway = rand() % 3;
    board[1][0].treasure = treasures[0];
    board[1][0].mobile = 1;
    board[3][0].boxtype = "T";
    board[3][0].boxway = rand() % 3;
    board[3][0].treasure = treasures[1];
    board[3][0].mobile = 1;
    board[5][0].boxtype = "T";
    board[5][0].boxway = rand() % 3;
    board[5][0].treasure = treasures[2];
    board[0][1].boxtype = "T";
    board[0][1].treasure = treasures[3];
    board[1][1].boxtype = "T";
    board[1][1].treasure = treasures[4];
    board[2][1].boxtype = "T";
    board[2][1].treasure = treasures[5];

    board[3][1].boxtype = "L";
    board[3][1].treasure = treasures[6];
    board[4][1].boxtype = "L";
    board[4][1].treasure = treasures[7];
    board[5][1].boxtype = "L";
    board[5][1].treasure = treasures[8];
    board[6][1].boxtype = "L";
    board[6][1].treasure = treasures[9];
    board[6][1].mobile = 1;
    board[1][2].boxtype = "L";
    board[1][2].boxway = rand() % 3;
    board[1][2].treasure = treasures[10];
    board[3][2].boxtype = "L";
    board[3][2].boxway = rand() % 3;
    board[3][2].treasure = treasures[11];
    board[3][2].mobile = 1;

    board[5][2].boxtype = "L";
    board[5][2].boxway = rand() % 3;
    board[5][2].mobile = 1;
    board[0][3].boxtype = "L";
    board[0][3].mobile = 1;
    board[1][3].boxtype = "L";
    board[2][3].boxtype = "L";
    board[3][3].boxtype = "L";
    board[4][3].boxtype = "L";
    board[5][3].boxtype = "L";
    board[6][3].boxtype = "L";
    board[1][4].boxtype = "L";
    board[1][4].boxway = rand() % 3;
    board[1][4].mobile = 1;
    board[3][4].boxtype = "L";
    board[3][4].boxway = rand() % 3;
    board[3][4].mobile = 1;

    board[5][4].boxtype = "I";
    board[5][4].boxway = rand() % 3;
    board[5][4].mobile = 1;
    board[0][5].boxtype = "I";
    board[1][5].boxtype = "I";
    board[2][5].boxtype = "I";
    board[3][5].boxtype = "I";
    board[4][5].boxtype = "I";
    board[5][5].boxtype = "I";
    board[6][5].boxtype = "I";
    board[1][6].boxtype = "I";
    board[1][6].boxway = rand() % 3;
    board[1][6].mobile = 1;
    board[3][6].boxtype = "I";
    board[3][6].boxway = rand() % 3;
    board[3][6].mobile = 1;
    board[5][6].boxtype = "I";
    board[5][6].boxway = rand() % 3;
    board[5][6].mobile = 1;
    substituteValue.boxtype = "I";
    substituteValue.boxway = rand() % 3;
    substituteValue.mobile = 1;


    //----SHUFFLE MOBILES----//
    for (int i = 0; i < NUM_MOVABLE_PIECES; i++) {
        // Generate two random indices to swap
        int indexA1 = rand() % NUM_MOVABLE_PIECES;
        int indexA2 = rand() % NUM_MOVABLE_PIECES;
        int indexB1 = rand() % NUM_MOVABLE_PIECES;
        int indexB2 = rand() % NUM_MOVABLE_PIECES;

        if((board[indexA1][indexA2].mobile == 1) || (board[indexB1][indexB2].mobile == 1)) {
            // Swap the pieces at the two indices
            Case temp = board[indexA1][indexA2];
            board[indexA1][indexA2] = board[indexB1][indexB2];
            board[indexB1][indexB2] = temp;
        }
        else {
            i--;
        }
    }
}
