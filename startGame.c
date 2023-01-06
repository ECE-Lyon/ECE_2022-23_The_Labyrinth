#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "startGame.h"

int player = 0;
int nbPlayer = 0;
int theEmperess = 0, theArchDruid = 0, theHauntedSeer = 0, theBrutalWanderer = 0;

char treasuresCard[NB_TREASURE_CARD][MAX_LETTERS_WORDS] = {"chauve souris", "epee", "dragon", "genie", "livre", "hiboux",
                                           "papillon", "cles", "scarabe", "champignon", "princesse", "diadem",
                                           "geant", "crane", "araignee", "couronne", "chandelier", "carte",
                                           "tresor", "serpent", "statut", "or", "souris", "fantome"};

Pawn theEmpressPawn = {0};
Pawn theArchDruidPawn = {0};
Pawn theHauntedSeerPawn = {0};
Pawn theBrutalWandererPawn = {0};

char treasureCardTheEmpress[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];
char treasureCardTheArchDruid[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];
char treasureCardTheHauntedSeer[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];
char treasureCardTheBrutalWanderer[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS];

Case board[BOARDSIZE][BOARDSIZE];


void distributeCards(char character[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS]) {
    for(int i = 0; i < NB_CARD_BY_PERSON; i++) {
        int res = 0;
        int randomCard = 0;
        while(res == 0) {
            randomCard = rand() % NB_TREASURE_CARD;
            res = strcmp(treasuresCard[randomCard], "0");
        }
        strcpy(character[i], treasuresCard[randomCard]);
        strcpy(treasuresCard[randomCard], "0");
    }
}

void boardCreation() {
    //----CORNERS----//
    strcpy(board[0][0].boxtype, "L");
    board[0][0].boxway = 1;
    strcpy(theEmpressPawn.boxtype, "L");
    theEmpressPawn.boxway = 1;
    theEmpressPawn.x = 0;
    theEmpressPawn.y = 0;
    strcpy(board[BOARDSIZE - 1][0].boxtype, "L");
    board[BOARDSIZE - 1][0].boxway = 2;
    strcpy(theArchDruidPawn.boxtype, "L");
    theArchDruidPawn.boxway = 2;
    theArchDruidPawn.x = BOARDSIZE - 1;
    theArchDruidPawn.y = 0;
    strcpy(board[0][BOARDSIZE - 1].boxtype, "L");
    board[0][BOARDSIZE - 1].boxway = 0;
    strcpy(theHauntedSeerPawn.boxtype, "L");
    theHauntedSeerPawn.boxway = 0;
    theHauntedSeerPawn.x = 0;
    theHauntedSeerPawn.y = BOARDSIZE - 1;
    strcpy(board[BOARDSIZE - 1][BOARDSIZE - 1].boxtype, "L");
    board[BOARDSIZE - 1][BOARDSIZE - 1].boxway = 3;
    strcpy(theBrutalWandererPawn.boxtype, "L");
    theBrutalWandererPawn.boxway = 3;
    theBrutalWandererPawn.x = BOARDSIZE - 1;
    theBrutalWandererPawn.y = BOARDSIZE - 1;


    //----OUTLINE----//
    for(int line = 2; line < BOARDSIZE - 3; line += 2) {
        strcpy(board[line][0].boxtype, "T");
        board[line][0].boxway = 0;
    }
    for(int line = 2; line < BOARDSIZE - 3; line += 2) {
        strcpy(board[line][BOARDSIZE - 1].boxtype, "T");
        board[line][BOARDSIZE - 1].boxway = 2;
    }
    for(int column = 2; column < BOARDSIZE - 1; column += 2) {
        strcpy(board[0][column].boxtype, "T");
        board[0][column].boxway = 3;
    }
    for(int column = 2; column < BOARDSIZE - 1; column += 2) {
        strcpy(board[BOARDSIZE - 1][column].boxtype, "T");
        board[BOARDSIZE - 1][column].boxway = 1;
    }


    //----CENTER----//
    strcpy(board[2][2].boxtype, "T");
    board[2][2].boxway = 3;
    strcpy(board[BOARDSIZE - 3][2].boxtype, "T");
    board[BOARDSIZE - 3][2].boxway = 0;
    strcpy(board[2][BOARDSIZE - 3].boxtype, "T");
    board[2][BOARDSIZE - 2].boxway = 1;
    strcpy(board[BOARDSIZE - 3][BOARDSIZE - 3].boxtype, "T");
    board[BOARDSIZE - 3][BOARDSIZE - 3].boxway = 2;

    //----MOBILES----//       ***************A CHANGER CAR COPIE COLLE***************
    //Case movableGameP;
    //for (int i = 0; i < NUM_MOVABLE_PIECES; i++) {
        // Generate two random indices to swap
        //int index1 = rand() % NUM_MOVABLE_PIECES;
        //int index2 = rand() % NUM_MOVABLE_PIECES;

        // Swap the pieces at the two indices
        //GamePiece temp = movableGameP[index1];
        //movableGameP[index1] = movableGameP[index2];
        //movableGameP[index2] = temp;
    //}
}

void soughtAfterTreasures(char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS], Pawn character) {
    printf("The treasure you are currently looking for is : %s \n", treasureCardCharacter[character.treasure]);
}


void startGame() {
    srand(time(NULL));

    //----PLAYERS----//
    printf("How many player are you ?\n");
    scanf("%d", &nbPlayer);
    while((nbPlayer < 2) || (nbPlayer > 4)){
        printf("Not enough player OR to much players\n");
        printf("How many player are you ?\n");
        scanf("%d", &nbPlayer);
    }
    for(int i = 1; i < nbPlayer + 1; i++){
        int differentCharacters = 0;
        while(differentCharacters == 0) {
            int chooseCharacter = 0;
            printf("Player %d, witch character do you want ?\nPress 1 for the Emperess, 2 for the Arch Druid, 3 for the Haunted Seer, 4 for the Brutal Wanderer\n", i);
            scanf("%d", &chooseCharacter);
            while ((chooseCharacter > 4) || (chooseCharacter < 1)) {
                printf("This is not a character\n");
                printf("Player %d, witch character do you want ?\nPress 1 for the Emperess, 2 for the Arch Druid, 3 for the Haunted Seer, 4 for the Brutal Wanderer\n",
                       i);
                scanf("%d", &chooseCharacter);
            }
            if ((chooseCharacter == 1) && (theEmperess == 0)) {
                theEmperess = i;
                differentCharacters = 1;
            }
            else if ((chooseCharacter == 2) && (theArchDruid == 0)) {
                theArchDruid = i;
                differentCharacters = 1;
            }
            else if ((chooseCharacter == 3) && (theHauntedSeer == 0)) {
                theHauntedSeer = i;
                differentCharacters = 1;
            }
            else if ((chooseCharacter == 4) && (theBrutalWanderer == 0)) {
                theBrutalWanderer = i;
                differentCharacters = 1;
            }
            else {printf("This character has already been chosen\n");}
        }
    }


    //----TREASURES----//
    distributeCards(treasureCardTheEmpress);
    distributeCards(treasureCardTheArchDruid);
    distributeCards(treasureCardTheHauntedSeer);
    distributeCards(treasureCardTheBrutalWanderer);


    //----START----//
    int firstPlayer = rand() % nbPlayer;
    boardCreation();
    initializeBoard();
    while(firstPlayer < nbPlayer + 1) {
        switch (firstPlayer) {
            case 0:
                if(theEmperess != 0){
                    printf("It's the turn of the Empress\n");
                    soughtAfterTreasures(treasureCardTheEmpress, theEmpressPawn);
                    oneRound(board, theEmpressPawn, treasureCardTheEmpress);
                }
                break;
            case 1 :
                if(theArchDruid != 0) {
                    printf("It's the turn of the Arch Druid\n");
                    soughtAfterTreasures(treasureCardTheArchDruid, theArchDruidPawn);
                    oneRound(board, theArchDruidPawn, treasureCardTheArchDruid);
                }
                break;
            case 2 :
                if(theHauntedSeer != 0) {
                    printf("It's the turn of the Haunted Seer\n");
                    soughtAfterTreasures(treasureCardTheHauntedSeer, theHauntedSeerPawn);
                    oneRound(board, theHauntedSeerPawn, treasureCardTheHauntedSeer);
                }
                break;
            case 3 :
                if(theBrutalWanderer != 0) {
                    printf("It's the turn of the Brutal Wanderer\n");
                    soughtAfterTreasures(treasureCardTheBrutalWanderer, theBrutalWandererPawn);
                    oneRound(board, theBrutalWandererPawn, treasureCardTheBrutalWanderer);
                }
                break;
            default:
                goto returnMainMenu;
        }
        firstPlayer++;
    }
    while(1) {
        for(player = 0; player < nbPlayer + 1; player++) {
            switch (player) {
                case 0:
                    if(theEmperess != 0) {
                        printf("It's the turn of the Empress\n");
                        soughtAfterTreasures(treasureCardTheEmpress, theEmpressPawn);
                        oneRound(board, theEmpressPawn, treasureCardTheEmpress);
                    }
                    break;
                case 1 :
                    if(theArchDruid != 0) {
                        printf("It's the turn of the Arch Druid\n");
                        soughtAfterTreasures(treasureCardTheArchDruid, theArchDruidPawn);
                        oneRound(board, theArchDruidPawn, treasureCardTheArchDruid);
                    }
                    break;
                case 2 :
                    if(theHauntedSeer != 0) {
                        printf("It's the turn of the Haunted Seer\n");
                        soughtAfterTreasures(treasureCardTheHauntedSeer, theHauntedSeerPawn);
                        oneRound(board, theHauntedSeerPawn, treasureCardTheHauntedSeer);
                    }
                    break;
                case 3 :
                    if(theBrutalWanderer != 0) {
                        printf("It's the turn of the Brutal Wanderer\n");
                        soughtAfterTreasures(treasureCardTheBrutalWanderer, theBrutalWandererPawn);
                        oneRound(board, theBrutalWandererPawn, treasureCardTheBrutalWanderer);
                    }
                    break;
                default:
                    goto returnMainMenu;
            }
            if (((theEmpressPawn.treasure == NB_CARD_BY_PERSON) && (theEmpressPawn.x == 0) && (theEmpressPawn.y == 0)) || ((theArchDruidPawn.treasure == NB_CARD_BY_PERSON) && (theArchDruidPawn.x == BOARDSIZE - 1) && (theArchDruidPawn.y == 0)) || ((theHauntedSeerPawn.treasure == NB_CARD_BY_PERSON) && (theHauntedSeerPawn.x == 0) && (theHauntedSeerPawn.y == BOARDSIZE - 1)) || ((theBrutalWandererPawn.treasure == NB_CARD_BY_PERSON) && (theBrutalWandererPawn.x == BOARDSIZE - 1) && (theBrutalWandererPawn.y == BOARDSIZE - 1))) {
                printf("\n\n    THE END \n\n");
            }
        }
    }

returnMainMenu:
    printf ("ERROR");
}
