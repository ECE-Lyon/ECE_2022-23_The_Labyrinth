#include <stdio.h>
#include "round.h"
#include "startGame.h"

int horizontal = 0, vertical = 0;
int choiceLine = 0;
int choice = 0;
int choiceWay = 0;

int oneRound() {
    for (horizontal = 0; horizontal < BOARDSIDE; horizontal++) {
        for(vertical = 0; vertical < BOARDSIDE; vertical++) {
            printf("%s ", board[horizontal][vertical].boxtype);
            printf("%d ", board[horizontal][vertical].boxway);
        }
        printf("\n");
    }

    printf("Do you want to move a row(1) or a column(2) ? \n");
    scanf("%d", &choice);
    printf("Which row/column do you want to replace ? \n");
    scanf("%d", &choiceLine);
    printf("Do you want to move to the right/down(1), or to the left/up(2) ? \n");
    scanf("%d", &choiceWay);

    //char *boxtype, *treasure; int boxway, theEmperess, theArchDruid, theHauntedSeer, theBrutalWanderer;
    if(choiceWay == 1) {
        if (choice == 1) {
            for (vertical = BOARDSIDE - 1; vertical > 0; vertical--) {
                board[vertical][choiceLine - 1] = board[vertical - 1][choiceLine - 1];
            }
            board[0][choiceLine - 1].boxtype = substituteValue.boxtype;
            board[0][choiceLine - 1].treasure = substituteValue.treasure;
            board[0][choiceLine - 1].boxway = substituteValue.boxway;
            board[0][choiceLine - 1].theEmperess = substituteValue.theEmperess;
            board[0][choiceLine - 1].theArchDruid = substituteValue.theArchDruid;
            board[0][choiceLine - 1].theHauntedSeer = substituteValue.theHauntedSeer;
            board[0][choiceLine - 1].theBrutalWanderer = substituteValue.theBrutalWanderer;
        } else if (choice == 2) {
            for (horizontal = BOARDSIDE - 1; horizontal > 0; horizontal--) {
                board[choiceLine - 1][horizontal] = board[choiceLine - 1][horizontal - 1];
            }
            board[choiceLine - 1][0].boxtype = substituteValue.boxtype;
            board[choiceLine - 1][0].treasure = substituteValue.treasure;
            board[choiceLine - 1][0].boxway = substituteValue.boxway;
            board[choiceLine - 1][0].theEmperess = substituteValue.theEmperess;
            board[choiceLine - 1][0].theArchDruid = substituteValue.theArchDruid;
            board[choiceLine - 1][0].theHauntedSeer = substituteValue.theHauntedSeer;
            board[choiceLine - 1][0].theBrutalWanderer = substituteValue.theBrutalWanderer;
        }
    }

    if(choiceWay == 2) {
        if (choice == 1) {
            for (vertical = 0; vertical < BOARDSIDE - 1; vertical++) {
                board[vertical][choiceLine - 1] = board[vertical + 1][choiceLine - 1];
            }
            board[BOARDSIDE - 1][choiceLine - 1].boxtype = substituteValue.boxtype;
            board[BOARDSIDE - 1][choiceLine - 1].treasure = substituteValue.treasure;
            board[BOARDSIDE - 1][choiceLine - 1].boxway = substituteValue.boxway;
            board[BOARDSIDE - 1][choiceLine - 1].theEmperess = substituteValue.theEmperess;
            board[BOARDSIDE - 1][choiceLine - 1].theArchDruid = substituteValue.theArchDruid;
            board[BOARDSIDE - 1][choiceLine - 1].theHauntedSeer = substituteValue.theHauntedSeer;
            board[BOARDSIDE - 1][choiceLine - 1].theBrutalWanderer = substituteValue.theBrutalWanderer;
        } else if (choice == 2) {
            for (horizontal = 0; horizontal < BOARDSIDE - 1; horizontal++) {
                board[choiceLine - 1][horizontal] = board[choiceLine - 1][horizontal + 1];
            }
            board[choiceLine - 1][BOARDSIDE - 1].boxtype = substituteValue.boxtype;
            board[choiceLine - 1][BOARDSIDE - 1].treasure = substituteValue.treasure;
            board[choiceLine - 1][BOARDSIDE - 1].boxway = substituteValue.boxway;
            board[choiceLine - 1][BOARDSIDE - 1].theEmperess = substituteValue.theEmperess;
            board[choiceLine - 1][BOARDSIDE - 1].theArchDruid = substituteValue.theArchDruid;
            board[choiceLine - 1][BOARDSIDE - 1].theHauntedSeer = substituteValue.theHauntedSeer;
            board[choiceLine - 1][BOARDSIDE - 1].theBrutalWanderer = substituteValue.theBrutalWanderer;
        }
    }


    for (horizontal = 0; horizontal < BOARDSIDE; horizontal++) {
        for(vertical = 0; vertical < BOARDSIDE; vertical++) {
            printf("%s ", board[horizontal][vertical].boxtype);
            printf("%d ", board[horizontal][vertical].boxway);
        }
        printf("\n");
    }


    //faire bouger pion
    //vérifier si le pion gagne un trésor
}

