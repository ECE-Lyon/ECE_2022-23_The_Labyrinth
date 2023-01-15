#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "startGame.h"

int player = 0;
int nbPlayer = 0;
int chooseTheEmperess = 0, chooseTheArchDruid = 0, chooseTheHauntedSeer = 0, chooseTheBrutalWanderer = 0;

Pawn theEmpressPawn = {0};
Pawn theArchDruidPawn = {0};
Pawn theHauntedSeerPawn = {0};
Pawn theBrutalWandererPawn = {0};

char treasures[NB_TREASURE_CARD][MAX_LETTERS_WORDS] = {"fairy", "bat", "dragon", "genie", "ghost", "ogre",
                                                       "salamander", "spider", "mouse", "owl", "beetle", "moth",
                                                       "book", "golden hood", "map", "crown", "keys", "skull",
                                                       "ring", "golden chest", "gemstone", "swordfish", "candlestick", "helmet"};

char treasureCardTheEmpress[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS] = {"fairy", "bat", "dragon", "genie", "ghost", "ogre"};
char treasureCardTheArchDruid[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS] = {"salamander", "spider", "mouse", "owl", "beetle", "moth"};
char treasureCardTheHauntedSeer[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS] = {"book", "golden hood", "map", "crown", "keys", "skull"};
char treasureCardTheBrutalWanderer[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS] = {"ring", "golden chest", "gemstone", "swordfish", "candlestick", "helmet"};

Case board[BOARDSIZE][BOARDSIZE] = {{0}};

Case substituteValue = {0};


void shuffleCards() {
    for(int i = 0; i < NB_CARD_BY_PERSON * 2; i++) {
        // Generate two random number to swap
        int nbA = rand() % NB_CARD_BY_PERSON;
        int nbB = rand() % NB_CARD_BY_PERSON;
        int nbC = rand() % NB_CARD_BY_PERSON;
        int nbD = rand() % NB_CARD_BY_PERSON;

        char randomCard[MAX_LETTERS_WORDS] = {0};

        // Swap the cards
        strcpy(randomCard, treasureCardTheEmpress[nbA]);
        strcpy(treasureCardTheEmpress[nbA], treasureCardTheArchDruid[nbB]);
        strcpy(treasureCardTheArchDruid[nbB], treasureCardTheHauntedSeer[nbC]);
        strcpy(treasureCardTheHauntedSeer[nbC], treasureCardTheBrutalWanderer[nbD]);
        strcpy(treasureCardTheBrutalWanderer[nbD], randomCard);
    }
}


void soughtAfterTreasures(char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS], Pawn character) {
    printf("\nThe treasure you are currently looking for is : %s \n\n", treasureCardCharacter[character.treasure]);
}


void startGame() {
    srand(time(NULL));

    //screenUpdate(4, images, charSelect,  staticTiles);

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
            if ((chooseCharacter == 1) && (chooseTheEmperess == 0)) {
                chooseTheEmperess = i;
                board[0][0].theEmperess = 1;
                differentCharacters = 1;
            }
            else if ((chooseCharacter == 2) && (chooseTheArchDruid == 0)) {
                chooseTheArchDruid = i;
                board[0][BOARDSIZE - 1].theArchDruid = 1;
                differentCharacters = 1;
            }
            else if ((chooseCharacter == 3) && (chooseTheHauntedSeer == 0)) {
                chooseTheHauntedSeer = i;
                board[BOARDSIZE - 1][0].theHauntedSeer = 1;
                differentCharacters = 1;
            }
            else if ((chooseCharacter == 4) && (chooseTheBrutalWanderer == 0)) {
                chooseTheBrutalWanderer = i;
                board[BOARDSIZE - 1][BOARDSIZE - 1].theBrutalWanderer = 1;
                differentCharacters = 1;
            }
            else {printf("This character has already been chosen\n");}
        }
    }


    //----TREASURES / CARDS----//
    shuffleCards();


    //----START----//
    substituteValue.boxtype = initializeBoard(theEmpressPawn, theArchDruidPawn, theHauntedSeerPawn, theBrutalWandererPawn, board, substituteValue, treasures);

    int firstPlayer = rand() % nbPlayer;
    while(firstPlayer < nbPlayer + 1) {
        switch (firstPlayer) {
            case 0:
                if(chooseTheEmperess != 0){
                    printf("\nIt's the turn of the Empress\n");
                    soughtAfterTreasures(treasureCardTheEmpress, theEmpressPawn);
                    printBoard(board);
                    oneRound(board, substituteValue, theEmpressPawn, treasureCardTheEmpress);
                }
                break;
            case 1 :
                if(chooseTheArchDruid != 0) {
                    printf("\nIt's the turn of the Arch Druid\n");
                    soughtAfterTreasures(treasureCardTheArchDruid, theArchDruidPawn);
                    printBoard(board);
                    oneRound(board, substituteValue, theArchDruidPawn, treasureCardTheArchDruid);
                }
                break;
            case 2 :
                if(chooseTheHauntedSeer != 0) {
                    printf("\nIt's the turn of the Haunted Seer\n");
                    soughtAfterTreasures(treasureCardTheHauntedSeer, theHauntedSeerPawn);
                    printBoard(board);
                    oneRound(board, substituteValue, theHauntedSeerPawn, treasureCardTheHauntedSeer);
                }
                break;
            case 3 :
                if(chooseTheBrutalWanderer != 0) {
                    printf("\nIt's the turn of the Brutal Wanderer\n");
                    soughtAfterTreasures(treasureCardTheBrutalWanderer, theBrutalWandererPawn);
                    printBoard(board);
                    oneRound(board, substituteValue, theBrutalWandererPawn, treasureCardTheBrutalWanderer);
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
                    if(chooseTheEmperess != 0) {
                        printf("\nIt's the turn of the Empress\n");
                        soughtAfterTreasures(treasureCardTheEmpress, theEmpressPawn);
                        printBoard(board);
                        oneRound(board, substituteValue, theEmpressPawn, treasureCardTheEmpress);
                    }
                    break;
                case 1 :
                    if(chooseTheArchDruid != 0) {
                        printf("\nIt's the turn of the Arch Druid\n");
                        soughtAfterTreasures(treasureCardTheArchDruid, theArchDruidPawn);
                        printBoard(board);
                        oneRound(board, substituteValue, theArchDruidPawn, treasureCardTheArchDruid);
                    }
                    break;
                case 2 :
                    if(chooseTheHauntedSeer != 0) {
                        printf("\nIt's the turn of the Haunted Seer\n");
                        soughtAfterTreasures(treasureCardTheHauntedSeer, theHauntedSeerPawn);
                        printBoard(board);
                        oneRound(board, substituteValue, theHauntedSeerPawn, treasureCardTheHauntedSeer);
                    }
                    break;
                case 3 :
                    if(chooseTheBrutalWanderer != 0) {
                        printf("\nIt's the turn of the Brutal Wanderer\n");
                        soughtAfterTreasures(treasureCardTheBrutalWanderer, theBrutalWandererPawn);
                        printBoard(board);
                        oneRound(board, substituteValue, theBrutalWandererPawn, treasureCardTheBrutalWanderer);
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
    printf ("\nERROR\n");
    al_rest(2.2);
}
