#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "startGame.h"

int player = 0;
int nbPlayer = 0;
int theEmperess = 0, theArchDruid = 0, theHauntedSeer = 0, theBrutalWanderer = 0;
char treasureCardTheEmperess[nbCardByPerson][maxLettersWords] = {0};
char treasureCardTheArchDruid[nbCardByPerson][maxLettersWords] = {0};
char treasureCardTheHauntedSeer[nbCardByPerson][maxLettersWords] = {0};
char treasureCardTheBrutalWanderer[nbCardByPerson][maxLettersWords] = {0};
char treasuresCard[nbTreasureCard][maxLettersWords] = {"chauve souris", "épée", "dragon", "génie", "livre", "hiboux",
                                           "papillon", "clés", "scarabé", "champignon", "princesse", "diadem",
                                           "géant", "crane", "araignée", "couronne", "chandelier", "carte",
                                           "trésor", "serpent", "statut", "or", "souris", "fantome"};


void distributeCards(char *character[nbCardByPerson][maxLettersWords]){
    int res = 0;
    for(int i = 0; i < nbCardByPerson; i++) {
        int randomCard = rand() % nbTreasureCard + 1;
        res = strcmp(treasuresCard[randomCard], "0");
        while(res == 0) {
            randomCard = rand() % nbTreasureCard + 1;
            res = strcmp(treasuresCard[randomCard], "0");
        }
        strcpy(character[i], treasuresCard[randomCard]);
        strcpy(treasuresCard[randomCard], "0");
    }
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
        int j = 0;
        printf("Player %d, witch character do you want ?\nPress 1 for theEmperess, 2 for theArchDruid, 3 for theHauntedSeer, 4 for theBrutalWanderer\n", i);
        scanf("%d", &j);
        while((j > 4) || (j < 1)){
            printf("This is not a character\n");
            printf("Player %d, witch character do you want ?\nPress 1 for theEmperess, 2 for theArchDruid, 3 for theHauntedSeer, 4 for theBrutalWanderer\n", i);
            scanf("%d", &j);
        }                                       //ERREUR : si +eurs personnes prennent le mm joueur, doit NE PAS fonctionner
        if(j == 1){theEmperess = i;}
        else if(j == 2){theArchDruid = i;}
        else if(j == 3){theHauntedSeer = i;}
        else if(j == 4){theBrutalWanderer = i;}
    }


    //----TREASURES----//
    distributeCards(treasureCardTheEmperess[nbCardByPerson][maxLettersWords]);
    distributeCards(treasureCardTheArchDruid[nbCardByPerson][maxLettersWords]);
    distributeCards(treasureCardTheHauntedSeer[nbCardByPerson][maxLettersWords]);
    distributeCards(treasureCardTheBrutalWanderer[nbCardByPerson][maxLettersWords]);

    for (int j = 0; j < nbCardByPerson; j++) {
        printf("%s ", treasureCardTheArchDruid[j]);
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < nbTreasureCard; i++) {
        printf("%s", treasuresCard[nbTreasureCard]);
        printf("\n");
    }


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
