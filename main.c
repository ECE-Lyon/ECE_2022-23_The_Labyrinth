#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "startGame.h"

char letter;

int main(void) {
    assert(al_init());

    printf("Welcome + explain games's rules\n\n");

    while(1) {
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
}
