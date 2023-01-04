#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "startGame.h"

int player = 0;
int nbPlayer = 0;
int theEmperess = 0, theArchDruid = 0, theHauntedSeer = 0, theBrutalWanderer = 0;

extern char treasureCardTheEmperess[nbCardByPerson][maxLettersWords];
extern char treasureCardTheArchDruid[nbCardByPerson][maxLettersWords];
extern char treasureCardTheHauntedSeer[nbCardByPerson][maxLettersWords];
extern char treasureCardTheBrutalWanderer[nbCardByPerson][maxLettersWords];
char treasuresCard[nbTreasureCard][maxLettersWords] = {"chauve souris", "epee", "dragon", "genie", "livre", "hiboux",
                                           "papillon", "cles", "scarabe", "champignon", "princesse", "diadem",
                                           "geant", "crane", "araignee", "couronne", "chandelier", "carte",
                                           "tresor", "serpent", "statut", "or", "souris", "fantome"};

Case substituteValue;
Case board[BOARDSIDE][BOARDSIDE] = {{0}};

Pawn theEmpressPawn = {0};
Pawn theArchDruidPawn = {0};
Pawn theHauntedSeerPawn = {0};
Pawn theBrutalWandererPawn = {0};


void distributeCards(char character[nbCardByPerson][maxLettersWords]) {
    for(int i = 0; i < nbCardByPerson; i++) {
        int res = 0;
        int randomCard = 0;
        while(res == 0) {
            randomCard = rand() % nbTreasureCard;
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
    strcpy(board[BOARDSIDE][0].boxtype, "L");
    board[BOARDSIDE][0].boxway = 2;
    strcpy(theArchDruidPawn.boxtype, "L");
    theArchDruidPawn.boxway = 2;
    theArchDruidPawn.x = BOARDSIDE;
    theArchDruidPawn.y = 0;
    strcpy(board[0][BOARDSIDE].boxtype, "L");
    board[0][BOARDSIDE].boxway = 0;
    strcpy(theHauntedSeerPawn.boxtype, "L");
    theHauntedSeerPawn.boxway = 0;
    theHauntedSeerPawn.x = 0;
    theHauntedSeerPawn.y = BOARDSIDE;
    strcpy(board[BOARDSIDE][BOARDSIDE].boxtype, "L");
    board[BOARDSIDE][BOARDSIDE].boxway = 3;
    strcpy(theBrutalWandererPawn.boxtype, "L");
    theBrutalWandererPawn.boxway = 3;
    theBrutalWandererPawn.x = BOARDSIDE;
    theBrutalWandererPawn.y = BOARDSIDE;


    //----OUTLINE----//
    for(int line = 2; line < BOARDSIDE - 2; line += 2) {
        strcpy(board[line][0].boxtype, "T");
        board[line][0].boxway = 0;
    }
    for(int line = 2; line < BOARDSIDE - 2; line += 2) {
        strcpy(board[line][BOARDSIDE].boxtype, "T");
        board[line][BOARDSIDE].boxway = 2;
    }
    for(int column = 2; column < BOARDSIDE; column += 2) {
        strcpy(board[0][column].boxtype, "T");
        board[0][column].boxway = 3;
    }
    for(int column = 2; column < BOARDSIDE; column += 2) {
        strcpy(board[BOARDSIDE][column].boxtype, "T");
        board[BOARDSIDE][column].boxway = 1;
    }

    //----CENTER----//
    strcpy(board[2][2].boxtype, "T");
    board[2][2].boxway = 3;
    strcpy(board[BOARDSIDE - 2][2].boxtype, "T");
    board[BOARDSIDE - 2][2].boxway = 0;
    strcpy(board[2][BOARDSIDE - 2].boxtype, "T");
    board[2][BOARDSIDE - 2].boxway = 1;
    strcpy(board[BOARDSIDE - 2][BOARDSIDE - 2].boxtype, "T");
    board[BOARDSIDE - 2][BOARDSIDE - 2].boxway = 2;
}

void soughtAfterTreasures() {
    printf("Your The treasure you are currently looking for is : %s", treasureCardTheEmperess[theEmpressPawn.treasure]);
    printf("Your The treasure you are currently looking for is : %s", treasureCardTheArchDruid[theArchDruidPawn.treasure]);
    printf("Your The treasure you are currently looking for is : %s", treasureCardTheHauntedSeer[theHauntedSeerPawn.treasure]);
    printf("Your The treasure you are currently looking for is : %s", treasureCardTheBrutalWanderer[theBrutalWandererPawn.treasure]);
}

void returnMainMenu(void) {
    //goto main;
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
    distributeCards(treasureCardTheEmperess);
    distributeCards(treasureCardTheArchDruid);
    distributeCards(treasureCardTheHauntedSeer);
    distributeCards(treasureCardTheBrutalWanderer);


    //----START----//
    int firstPlayer = rand() % nbPlayer - 1;
    boardCreation();
    while(firstPlayer < 3) {
        soughtAfterTreasures();
        //round();
        firstPlayer++;
    }
    while(1) {
        for(player = 0; player < 3; player++) {
            soughtAfterTreasures();
            //round();
            if (((theEmpressPawn.treasure == nbCardByPerson) && (theEmpressPawn.x == 0) && (theEmpressPawn.y == 0)) || ((theArchDruidPawn.treasure == nbCardByPerson) && (theArchDruidPawn.x == 0) && (theArchDruidPawn.y == 0)) || ((theHauntedSeerPawn.treasure == nbCardByPerson) && (theHauntedSeerPawn.x == 0) && (theHauntedSeerPawn.y == 0)) || ((theBrutalWandererPawn.treasure == nbCardByPerson) && (theBrutalWandererPawn.x == 0) && (theBrutalWandererPawn.y == 0))) {
                printf("END");
                returnMainMenu();
            }
        }
    }

    //pour les tuiles à ne pas faire coulisser, faire une condition genre "si la ligne/colonne choisie != 1, 3 ou 5" alors on repose la question
    //mettre un return 0 pour arreter le programme si on veut qu'il s'arrete (dans la fct où on demande à un joueur qqc
}
