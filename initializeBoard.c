#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initializeBoard.h"

// Array to store the starting positions of the static pieces
GamePiece staticGamePieces[NUM_STATIC_PIECES] = {
  {0, 0, 1},  // Piece 1 starting position
  {2, 0, 2},  // Piece 2 starting position
  {4, 0, 3},  // Piece 3 starting position
  {6, 0, 4},  // Piece 4 starting position
  {0, 2, 5},  // Piece 5 starting position
  {2, 2, 6},  // Piece 6 starting position
  {4, 2, 7},  // Piece 7 starting position
  {6, 2, 8},  // Piece 8 starting position
  {0, 4, 9},  // Piece 9 starting position
  {2, 4, 10}, // Piece 10 starting position
  {4, 4, 11}, // Piece 11 starting position
  {6, 4, 12}, // Piece 12 starting position
  {0, 6, 13}, // Piece 13 starting position
  {2, 6, 14}, // Piece 14 starting position
  {4, 6, 15}, // Piece 15 starting position
  {6, 6, 16}  // Piece 16 starting position
};

// Array to store the starting positions of the movable pieces
GamePiece movableGamePieces[NUM_MOVABLE_PIECES] = {
  {1, 0, 17},  // Piece 01 starting position
  {3, 0, 18},  // Piece 02 starting position
  {5, 0, 19},  // Piece 03 starting position
  {0, 1, 20},  // Piece 04 starting position
  {1, 1, 21},  // Piece 05 starting position
  {2, 1, 22},  // Piece 06 starting position
  {3, 1, 23},  // Piece 07 starting position
  {4, 1, 24},  // Piece 08 starting position
  {5, 1, 25},  // Piece 09 starting position
  {6, 1, 26},  // Piece 10 starting position
  {1, 2, 27},  // Piece 11 starting position
  {3, 2, 28},  // Piece 12 starting position
  {5, 2, 29},  // Piece 13 starting position
  {0, 3, 30},  // Piece 14 starting position
  {1, 3, 31},  // Piece 15 starting position
  {2, 3, 32},  // Piece 16 starting position
  {3, 3, 33},  // Piece 17 starting position
  {4, 3, 34},  // Piece 18 starting position
  {5, 3, 35},  // Piece 19 starting position
  {6, 3, 36},  // Piece 20 starting position
  {1, 4, 37},  // Piece 21 starting position
  {3, 4, 38},  // Piece 22 starting position
  {5, 4, 39},  // Piece 23 starting position
  {0, 5, 40},  // Piece 24 starting position
  {1, 5, 41},  // Piece 25 starting position
  {2, 5, 42},  // Piece 26 starting position
  {3, 5, 43},  // Piece 27 starting position
  {4, 5, 44},  // Piece 28 starting position
  {5, 5, 45},  // Piece 29 starting position
  {6, 5, 46},  // Piece 30 starting position
  {1, 6, 47},  // Piece 31 starting position
  {3, 6, 48},  // Piece 32 starting position
  {5, 6, 49}   // Piece 33 starting position
};

// Two-dimensional array to represent the game board
int boardPieces[BOARDSIDE][BOARDSIDE];

// Initializes the game board and places the game pieces in their starting positions
void initializeGame() {
  // Initialize the game board to all zeros
  for (int i = 0; i < BOARDSIDE; i++) {
    for (int j = 0; j < BOARDSIDE; j++) {
      boardPieces[i][j] = 0;
    }
  }
 

  // Place the static pieces in their fixed positions
  for (int i = 0; i < NUM_STATIC_PIECES; i++) {
    int x = staticGamePieces[i].x;
    int y = staticGamePieces[i].y;
    int number = staticGamePieces[i].number;
    boardPieces[x][y] = number;
  }


  // Place the movable pieces in their starting positions
  for (int i = 0; i < NUM_MOVABLE_PIECES; i++) {
    int x = movableGamePieces[i].x;
    int y = movableGamePieces[i].y;
    int number = movableGamePieces[i].number;
    boardPieces[x][y] = number;
  }
}


 void shuffleMovablePieces() {
   // Seed the random number generator based on the time
   srand(time(NULL));

   // Shuffle the movable pieces by swapping two pieces at random indices
   for (int i = 0; i < NUM_MOVABLE_PIECES; i++) {
     // Generate two random indices to swap
    int index1 = rand() % NUM_MOVABLE_PIECES;
     int index2 = rand() % NUM_MOVABLE_PIECES;

     // Swap the pieces at the two indices
     GamePiece temp = movableGamePieces[index1];
     movableGamePieces[index1] = movableGamePieces[index2];
     movableGamePieces[index2] = temp;
    }
 }


void initializeBoard() {
  // Initialize the game
  initializeGame();

  shuffleMovablePieces();

  // Print the game board
  //for (int i = 0; i < BOARDSIDE; i++) {
    //for (int j = 0; j < BOARDSIDE; j++) {
      //printf("%d ", boardPieces[i][j]);
    //}
    //printf("\n");
  //}
}
