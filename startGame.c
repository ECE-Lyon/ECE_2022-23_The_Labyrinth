#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "startGame.h"

int player = 0;
int nbPlayer = 0;
int theEmperess = 0, theArchDruid = 0, theHauntedSeer = 0, theBrutalWanderer = 0;

char treasureCardTheEmperess[nbCardByPerson][maxLettersWords] = {{0}};
char treasureCardTheArchDruid[nbCardByPerson][maxLettersWords] = {{0}};
char treasureCardTheHauntedSeer[nbCardByPerson][maxLettersWords] = {{0}};
char treasureCardTheBrutalWanderer[nbCardByPerson][maxLettersWords] = {{0}};
char treasuresCard[nbTreasureCard][maxLettersWords] = {"chauve souris", "epee", "dragon", "genie", "livre", "hiboux",
                                           "papillon", "cles", "scarabe", "champignon", "princesse", "diadem",
                                           "geant", "crane", "araignee", "couronne", "chandelier", "carte",
                                           "tresor", "serpent", "statut", "or", "souris", "fantome"};

Case substituteValue;
Case board[BOARDSIDE][BOARDSIDE] = {{0}};


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
    strcpy(board[BOARDSIDE][0].boxtype, "L");
    board[BOARDSIDE][0].boxway = 2;
    strcpy(board[0][BOARDSIDE].boxtype, "L");
    board[0][BOARDSIDE].boxway = 0;
    strcpy(board[BOARDSIDE][BOARDSIDE].boxtype, "L");
    board[BOARDSIDE][BOARDSIDE].boxway = 3;

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


    //----WHO START ?----//
    player = rand() % nbPlayer - 1;
    boardCreation();
    //est-ce vraiment nécessaire que les tuile fixes portent toujours les mêmes trésors ?

    //pour les tuiles à ne pas faire coulisser, faire une condition genre "si la ligne/colonne choisie != 1, 3 ou 5" alors on repose la question

    //while("pas dédection de partie finie") {    //créer une fct d'arret pour détecter quand un jour gagne
        //while(player, player < 3, player++) {
        //    //round
        //}
        //player = 0;
    //}
}
