#include <stdio.h>
#include "round.h"

int horizontal = 0, vertical = 0;
int choiceLine = 0;
int choice = 0;
int choiceWay = 0;

int oneRound(Case board[BOARDSIZE][BOARDSIZE], Case substituteValue, Pawn character, char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS]) {
    printf("Do you want to move a row(1) or a column(2) ? \n");
    scanf("%d", &choice);
    printf("Which row/column do you want to replace ? \n");
    scanf("%d", &choiceLine);
    while(!((choiceLine == 1 + 1) || (choiceLine == 3 + 1) || (choiceLine == 5 + 1))) {
        printf("You can't move the row/column, only 2, 4 and 6 are available. Which row/column do you want to replace ? \n");
        scanf("%d", &choiceLine);
    }
    printf("Do you want to move to the right/down(1), or to the left/up(2) ? \n");
    scanf("%d", &choiceWay);

    if(choiceWay == 1) {
        if (choice == 1) {
            for (vertical = BOARDSIZE - 1; vertical > 0; vertical--) {
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
            for (horizontal = BOARDSIZE - 1; horizontal > 0; horizontal--) {
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
            for (vertical = 0; vertical < BOARDSIZE - 1; vertical++) {
                board[vertical][choiceLine - 1] = board[vertical + 1][choiceLine - 1];
            }
            board[BOARDSIZE - 1][choiceLine - 1].boxtype = substituteValue.boxtype;
            board[BOARDSIZE - 1][choiceLine - 1].treasure = substituteValue.treasure;
            board[BOARDSIZE - 1][choiceLine - 1].boxway = substituteValue.boxway;
            board[BOARDSIZE - 1][choiceLine - 1].theEmperess = substituteValue.theEmperess;
            board[BOARDSIZE - 1][choiceLine - 1].theArchDruid = substituteValue.theArchDruid;
            board[BOARDSIZE - 1][choiceLine - 1].theHauntedSeer = substituteValue.theHauntedSeer;
            board[BOARDSIZE - 1][choiceLine - 1].theBrutalWanderer = substituteValue.theBrutalWanderer;
        } else if (choice == 2) {
            for (horizontal = 0; horizontal < BOARDSIZE - 1; horizontal++) {
                board[choiceLine - 1][horizontal] = board[choiceLine - 1][horizontal + 1];
            }
            board[choiceLine - 1][BOARDSIZE - 1].boxtype = substituteValue.boxtype;
            board[choiceLine - 1][BOARDSIZE - 1].treasure = substituteValue.treasure;
            board[choiceLine - 1][BOARDSIZE - 1].boxway = substituteValue.boxway;
            board[choiceLine - 1][BOARDSIZE - 1].theEmperess = substituteValue.theEmperess;
            board[choiceLine - 1][BOARDSIZE - 1].theArchDruid = substituteValue.theArchDruid;
            board[choiceLine - 1][BOARDSIZE - 1].theHauntedSeer = substituteValue.theHauntedSeer;
            board[choiceLine - 1][BOARDSIZE - 1].theBrutalWanderer = substituteValue.theBrutalWanderer;
        }
    }

    //faire bouger pion
    //vérifier si le pion gagne un trésor

    return 0;
}
