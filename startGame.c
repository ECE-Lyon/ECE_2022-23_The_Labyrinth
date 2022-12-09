#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "startGame.h"

//void distributeCards(char *player[nbCardByPerson]){
//    for(int i = 0; i < nbCardByPerson; i++) {
//        int randomCard = rand() % nbTreasureCard + 1;
//        if(treasuresCard[randomCard] == "0") {
//            randomCard = rand() % nbTreasureCard + 1;
//            player[i] = treasuresCard[randomCard];
//            strcpy(treasuresCard[randomCard], "0");
//        }
//    }
//}

void startGame() {
    srand(time(NULL));

    //----PLAYERS----//
    printf("How many player are you ?");
    scanf("%d", &nbPlayer);
    while(nbPlayer < 2) {
        printf("Not enough player");
        printf("How many player are you ?");
        scanf("%d", &nbPlayer);
    }
    while(nbPlayer > 4) {
        printf("To much players");
        printf("How many player are you ?");
        scanf("%d", &nbPlayer);
    }
    for(int i = 1; i < nbPlayer + 1; i++) {
        int j = 0;
        printf("Player %d, witch character do you want ?\nPress 1 for theEmperess, 2 for theArchDruid, 3 for theHauntedSeer, 4 for theBrutalWanderer", i);
        scanf("%d", &j);
        while((j > 4) || (j < 1)){
            printf("This is not a character");
            printf("Player %d, witch character do you want ?\nPress 1 for theEmperess, 2 for theArchDruid, 3 for theHauntedSeer, 4 for theBrutalWanderer", i);
            scanf("%d", &j);
        }
        if(j == 1){theEmperess = i;}
        else if(j == 2){theArchDruid = i;}
        else if(j == 3){theHauntedSeer = i;}
        else if(j == 4){theBrutalWanderer = i;}
    }


    //----TREASURES----//
    //distributeCards(*treasureCardTheEmperess[nbCardByPerson]);
    //distributeCards(*treasureCardTheArchDruid[nbCardByPerson]);
    //distributeCards(*treasureCardTheHauntedSeer[nbCardByPerson]);
    //distributeCards(*treasureCardTheBrutalWanderer[nbCardByPerson]);


    //----WHO START ?----//


    //joueur choisi aléatoirement pour commencer (player = nbr aléatoire entre 0 et 3)
    //génération du plateau (sous forme de tableau)
    // [...]

    //while("pas dédection de partie finie") {    //créer une fct d'arret pour détecter quand un jour gagne
        //while(player, player < 3, player++) {
        //    //round
        //}
        //player = 0;
    //}
}
