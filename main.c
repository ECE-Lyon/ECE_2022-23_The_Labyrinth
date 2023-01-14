#include <stdio.h>
#include "struct_macro.h"
#include "initializeAllegro.h"
#include "startGame.h"

char letter;

int main(void) {

    printf("\nWELCOME\n\n");

    while(1) {
        initializeAllegro();
        screenUpdate();
        printf("Main menu:\n");
        printf("1) Start game\n");
        printf("2) Rules\n");
        printf("3) Quit\n");
        printf("Enter the number of your selection: ");

        // Prompt the user to enter their selection
        int selection;
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                startGame();
                break;
            case 2 :
                screenUpdate();
                while(letter != *"m") {
                    scanf("%c", &letter);
                }
                break;
            case 3 :
                return 0;
            default:
                printf("ERROR");
                return 0;
        }
    }
    cleanUp();
}
