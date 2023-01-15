#include <stdio.h>
#include "struct_macro.h"
#include "initializeAllegro.h"
#include "startGame.h"

int main(void) {

    printf("\nWELCOME\n\n");

    while (1) {
        initializeAllegro();
        screenUpdate(0);

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        // Check for events
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ENTER:
                    startGame();
                    break;
                case ALLEGRO_KEY_M :
                    screenUpdate(0);
                    break;
                case ALLEGRO_KEY_A :
                    screenUpdate(1);
                    break;
                case ALLEGRO_KEY_D :
                    screenUpdate(2);
                    break;
                case ALLEGRO_KEY_TAB :
                    return 0;
                default:
                    printf("ERROR");
                    return 0;
            }
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        cleanUp();
    }
}
