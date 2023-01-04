#include <stdio.h>
#include "startGame.h"

extern int main(void) {
    printf("Welcome + explain games's rules\n\n");

    while(1) {
        printf("Main menu:\n");
        printf("1) Start game\n");
        printf("2) Quit\n");
        printf("Enter the number of your selection: ");

        // Prompt the user to enter their selection
        int selection;
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                startGame();
                break;
            case 2 :
                return 0;
        }
    }
}
