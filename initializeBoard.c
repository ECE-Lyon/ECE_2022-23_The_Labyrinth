#include <stdio.h>
#include <stdlib.h>
#include "initializeBoard.h"

char* initializeBoard(Pawn theEmpressPawn, Pawn theArchDruidPawn, Pawn theHauntedSeerPawn, Pawn theBrutalWandererPawn, Case board[BOARDSIZE][BOARDSIZE], Case substituteValue, char treasures[NB_TREASURE_CARD][MAX_LETTERS_WORDS]) {

    srand(time(NULL));

    //----CORNERS----//
    board[0][0].boxtype = "L";
    board[0][0].boxway = 1;
    board[0][BOARDSIZE - 1].boxtype = "L";
    board[0][BOARDSIZE - 1].boxway = 2;
    board[BOARDSIZE - 1][0].boxtype = "L";
    board[BOARDSIZE - 1][0].boxway = 0;
    board[BOARDSIZE - 1][BOARDSIZE - 1].boxtype = "L";
    board[BOARDSIZE - 1][BOARDSIZE - 1].boxway = 3;


    //----OUTLINE----//
    board[2][0].treasure = treasures[12];
    board[4][0].treasure = treasures[13];
    for(int line = 2; line < BOARDSIZE - 2; line += 2) { //UP
        board[line][0].boxtype = "T";
        board[line][0].boxway = 3;
    }

    board[2][BOARDSIZE - 1].treasure = treasures[22];
    board[4][BOARDSIZE - 1].treasure = treasures[23];
    for(int line = 2; line < BOARDSIZE - 2; line += 2) { //DOWN
        board[line][BOARDSIZE - 1].boxtype = "T";
        board[line][BOARDSIZE - 1].boxway = 1;
    }

    board[0][2].treasure = treasures[14];
    board[0][4].treasure = treasures[18];
    for(int column = 2; column < BOARDSIZE - 2; column += 2) { //LEFT
        board[0][column].boxtype = "T";
        board[0][column].boxway = 0;
    }

    board[BOARDSIZE - 1][2].treasure = treasures[17];
    board[BOARDSIZE - 1][4].treasure = treasures[21];
    for(int column = 2; column < BOARDSIZE - 2; column += 2) { //RIGHT
        board[BOARDSIZE - 1][column].boxtype = "T";
        board[BOARDSIZE - 1][column].boxway = 2;
    }


    //----CENTER----//
    board[2][2].boxtype = "T";
    board[2][2].boxway = 3;
    board[2][2].treasure = treasures[15];
    board[BOARDSIZE - 3][2].boxtype = "T";
    board[BOARDSIZE - 3][2].boxway = 2;
    board[BOARDSIZE - 3][2].treasure = treasures[16];
    board[2][BOARDSIZE - 3].boxtype = "T";
    board[2][BOARDSIZE - 3].boxway = 0;
    board[2][BOARDSIZE - 3].treasure = treasures[19];
    board[BOARDSIZE - 3][BOARDSIZE - 3].boxtype = "T";
    board[BOARDSIZE - 3][BOARDSIZE - 3].boxway = 1;
    board[BOARDSIZE - 3][BOARDSIZE - 3].treasure = treasures[20];


    //----CREATION MOBILES----//
    for(int i = 0; i < BOARDSIZE; i++) {
        board[i][1].mobile = 1;
    }
    for(int i = 0; i < BOARDSIZE; i++) {
        board[i][3].mobile = 1;
        board[i][3].boxtype = "L";
    }
    for(int i = 0; i < BOARDSIZE; i++) {
        board[i][5].mobile = 1;
        board[i][5].boxtype = "I";
    }
    board[1][0].boxtype = "T";
    board[1][0].treasure = treasures[0];
    board[1][0].mobile = 1;
    board[3][0].boxtype = "T";
    board[3][0].treasure = treasures[1];
    board[3][0].mobile = 1;
    board[5][0].boxtype = "T";
    board[5][0].treasure = treasures[2];
    board[5][0].mobile = 1;
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
    board[1][2].treasure = treasures[10];
    board[1][2].mobile = 1;
    board[3][2].boxtype = "L";
    board[3][2].treasure = treasures[11];
    board[3][2].mobile = 1;

    board[5][2].boxtype = "L";
    board[5][2].mobile = 1;
    board[1][4].boxtype = "L";
    board[1][4].mobile = 1;
    board[3][4].boxtype = "L";
    board[3][4].mobile = 1;

    board[5][4].boxtype = "I";
    board[5][4].mobile = 1;
    board[1][6].boxtype = "I";
    board[1][6].mobile = 1;
    board[3][6].boxtype = "I";
    board[3][6].mobile = 1;
    board[5][6].boxtype = "I";
    board[5][6].mobile = 1;


    //----EXTRA PIECE----//
    substituteValue.boxtype = "I";
    substituteValue.mobile = 1;


    //----SHUFFLE MOBILES----//
    // For the substituteValue
    int index1 = rand() % BOARDSIZE;
    int index2 = rand() % BOARDSIZE;
    while (board[index1][index2].mobile == 0) {
        index1 = rand() % BOARDSIZE;
        index2 = rand() % BOARDSIZE;
    }
    /*Case temp = board[index1][index2];
    board[index1][index2] = substituteValue;
    substituteValue = temp;*/

    // For the board
    for (int i = 0; i < BOARDSIZE * BOARDSIZE; i++) {
        // Generate two random indices to swap
        int indexA1 = rand() % BOARDSIZE;
        int indexA2 = rand() % BOARDSIZE;
        int indexB1 = rand() % BOARDSIZE;
        int indexB2 = rand() % BOARDSIZE;

        if((board[indexA1][indexA2].mobile == 1) && (board[indexB1][indexB2].mobile == 1)) {
            //Turn the pieces
            board[indexA1][indexA2].boxway = rand() % 3;
            board[indexB1][indexB2].boxway = rand() % 3;

            //Swap the pieces at the two indices
            Case temp = board[indexA1][indexA2];
            board[indexA1][indexA2] = board[indexB1][indexB2];
            board[indexB1][indexB2] = temp;
        }
        else {
            i--;
        }
    }

    return (substituteValue.boxtype);
}
