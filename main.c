#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "startGame.h"

#define NB_IMAGES 21
#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

char letter;

int main(void) {

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_BITMAP *images[NB_IMAGES];

    // Initialize Allegro
    al_init();
    al_init_image_addon();
    al_install_keyboard();

    // Get the primary monitor's display mode
    ALLEGRO_DISPLAY_MODE display_mode;
    al_get_display_mode(0, &display_mode);

    // Calculate the coordinates to center the window on the primary monitor
    int x = (display_mode.width - DISPLAY_WIDTH) / 2;
    int y = (display_mode.height - DISPLAY_HEIGHT) / 2;


    //create the display
    display=al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW | ALLEGRO_RESIZABLE | ALLEGRO_NOFRAME); //window specs
    al_set_window_title(display, "LABYRINTH: Extended version"); //window name
    al_set_window_position(display, x, y); // Set the window's position


    // Create an event queue
    event_queue = al_create_event_queue();

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
