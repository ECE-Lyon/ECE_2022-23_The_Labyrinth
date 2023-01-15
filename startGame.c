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


void loop(int var, ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33]) {
    switch (var) {
        case 0:
            if (chooseTheEmperess != 0) {
                printf("\nIt's the turn of the Empress\n");
                soughtAfterTreasures(treasureCardTheEmpress, theEmpressPawn);
                screenUpdate(9, images, charSelect, staticTiles, movableTiles, 0, 0);
                printBoard(board);
                board[theEmpressPawn.x][theEmpressPawn.y].theEmperess = 0;
                oneRound(display, event_queue, images, charSelect,  staticTiles, movableTiles, board, substituteValue, theEmpressPawn, treasureCardTheEmpress);
                board[theEmpressPawn.x][theEmpressPawn.y].theEmperess = 1;
            }
            break;
        case 1 :
            if (chooseTheArchDruid != 0) {
                printf("\nIt's the turn of the Arch Druid\n");
                soughtAfterTreasures(treasureCardTheArchDruid, theArchDruidPawn);
                screenUpdate(9, images, charSelect, staticTiles, movableTiles, 0, 0);
                printBoard(board);
                board[theArchDruidPawn.x][theArchDruidPawn.y].theArchDruid = 0;
                oneRound(display, event_queue, images, charSelect,  staticTiles, movableTiles, board, substituteValue, theArchDruidPawn, treasureCardTheArchDruid);
                board[theArchDruidPawn.x][theArchDruidPawn.y].theArchDruid = 1;
            }
            break;
        case 2 :
            if (chooseTheHauntedSeer != 0) {
                printf("\nIt's the turn of the Haunted Seer\n");
                soughtAfterTreasures(treasureCardTheHauntedSeer, theHauntedSeerPawn);
                screenUpdate(9, images, charSelect, staticTiles, movableTiles, 0, 0);
                printBoard(board);
                board[theHauntedSeerPawn.x][theHauntedSeerPawn.y].theHauntedSeer = 0;
                oneRound(display, event_queue, images, charSelect,  staticTiles, movableTiles, board, substituteValue, theHauntedSeerPawn, treasureCardTheHauntedSeer);
                board[theHauntedSeerPawn.x][theHauntedSeerPawn.y].theHauntedSeer = 0;
            }
            break;
        case 3 :
            if (chooseTheBrutalWanderer != 0) {
                printf("\nIt's the turn of the Brutal Wanderer\n");
                soughtAfterTreasures(treasureCardTheBrutalWanderer, theBrutalWandererPawn);
                screenUpdate(9, images, charSelect, staticTiles, movableTiles, 0, 0);
                printBoard(board);
                board[theBrutalWandererPawn.x][theBrutalWandererPawn.y].theBrutalWanderer = 0;
                oneRound(display, event_queue, images, charSelect,  staticTiles, movableTiles, board, substituteValue, theBrutalWandererPawn, treasureCardTheBrutalWanderer);
                board[theBrutalWandererPawn.x][theBrutalWandererPawn.y].theBrutalWanderer = 0;
            }
            break;
        default :
            goto returnMainMenu;
    }

    returnMainMenu:
        printf("\nERROR\n");
        al_rest(2.2);
}


int startGame(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33]) {
    srand(time(NULL));

    screenUpdate(3, images, charSelect, staticTiles, movableTiles, 0, 0);

    //----PLAYERS----//
    printf("How many player are you ?\n");

    while (nbPlayer == 0) {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_2) {
                nbPlayer = 2;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_3) {
                nbPlayer = 3;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_4) {
                nbPlayer = 4;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_M) {
                goto returnMainMenu;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_TAB) {
                return 0;
            } else {
                screenUpdate(7, images, charSelect, staticTiles, movableTiles, 0, 0);
            }
        }
    }

    screenUpdate(4, images, charSelect, staticTiles, movableTiles, 5, 1);

    for (int i = 1; i < nbPlayer + 1; i++) {
        int differentCharacters = 0;
        printf("Player %d, witch character do you want ?\nPress 1 for the Emperess, 2 for the Arch Druid, 3 for the Haunted Seer, 4 for the Brutal Wanderer\n",
               i);

        while (differentCharacters == 0) {

            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue, &event);

            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if ((event.keyboard.keycode == ALLEGRO_KEY_1) && (chooseTheEmperess == 0)) {
                    chooseTheEmperess = i;
                    board[0][0].theEmperess = 1;
                    differentCharacters = 1;
                    screenUpdate(4, images, charSelect, staticTiles, movableTiles, 0, 0);
                    al_rest(1.0);
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_2) && (chooseTheArchDruid == 0)) {
                    chooseTheArchDruid = i;
                    board[0][BOARDSIZE - 1].theArchDruid = 1;
                    differentCharacters = 1;
                    screenUpdate(4, images, charSelect, staticTiles, movableTiles, 1, 0);
                    al_rest(1.0);
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_3) && (chooseTheHauntedSeer == 0)) {
                    chooseTheHauntedSeer = i;
                    board[BOARDSIZE - 1][0].theHauntedSeer = 1;
                    differentCharacters = 1;
                    screenUpdate(4, images, charSelect, staticTiles, movableTiles, 2, 0);
                    al_rest(1.0);
                }
                if ((event.keyboard.keycode == ALLEGRO_KEY_4) && (chooseTheBrutalWanderer == 0)) {
                    chooseTheBrutalWanderer = i;
                    board[BOARDSIZE - 1][BOARDSIZE - 1].theBrutalWanderer = 1;
                    differentCharacters = 1;
                    screenUpdate(4, images, charSelect, staticTiles, movableTiles, 3, 0);
                    al_rest(1.0);
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_M) {
                    goto returnMainMenu;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_TAB) {
                    return 0;
                }
            }
        }
    }

    screenUpdate(5, images, charSelect, staticTiles, movableTiles, 0, 0);


    //----TREASURES / CARDS----//
    shuffleCards();


    //----BOARD----//
    substituteValue.boxtype = initializeBoard(theEmpressPawn, theArchDruidPawn, theHauntedSeerPawn, theBrutalWandererPawn, board, substituteValue, treasures);


    //----START----//
    int k = 0;
    while (k == 0) {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_D) {
                screenUpdate(9, images, charSelect, staticTiles, movableTiles, 0, 0);
                k = 1;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_M) {
                goto returnMainMenu;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_TAB) {
                return 0;
            }
        }
    }

    int firstPlayer = rand() % nbPlayer;
    while (firstPlayer < nbPlayer) {

        loop(firstPlayer, display, event_queue, images, charSelect,  staticTiles, movableTiles);

        firstPlayer++;
    }

    while (1) {
        for (player = 0; player < nbPlayer; player++) {

            loop(player, display, event_queue, images, charSelect,  staticTiles, movableTiles);

            if (((theEmpressPawn.treasure == NB_CARD_BY_PERSON) && (theEmpressPawn.x == 0) &&
                 (theEmpressPawn.y == 0)) ||
                ((theArchDruidPawn.treasure == NB_CARD_BY_PERSON) && (theArchDruidPawn.x == BOARDSIZE - 1) &&
                 (theArchDruidPawn.y == 0)) ||
                ((theHauntedSeerPawn.treasure == NB_CARD_BY_PERSON) && (theHauntedSeerPawn.x == 0) &&
                 (theHauntedSeerPawn.y == BOARDSIZE - 1)) ||
                ((theBrutalWandererPawn.treasure == NB_CARD_BY_PERSON) &&
                 (theBrutalWandererPawn.x == BOARDSIZE - 1) && (theBrutalWandererPawn.y == BOARDSIZE - 1))) {
                printf("\n\n    THE END \n\n");
            }
        }
    }
    returnMainMenu:
        printf("\nERROR\n");
        al_rest(2.2);
        return 0;
}
