#include <stdio.h>
#include "initializeAllegro.h"
#include "startGame.h"


int main(void) {

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT_QUEUE *charEventQueue = NULL;
    ALLEGRO_BITMAP *images[NB_IMAGES];
    ALLEGRO_BITMAP *charSelect[4];
    ALLEGRO_BITMAP *staticTiles[16];

    initializeAllegro(display, event_queue, charEventQueue, images, charSelect, staticTiles);
    screenUpdate(0, images, charSelect,  staticTiles);

    while (1) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        // Check for events
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ENTER:
                    startGame();
                    break;
                case ALLEGRO_KEY_M :
                    screenUpdate(0, images, charSelect,  staticTiles);
                    break;
                case ALLEGRO_KEY_A :
                    screenUpdate(1, images, charSelect,  staticTiles);
                    break;
                case ALLEGRO_KEY_D :
                    screenUpdate(2, images, charSelect,  staticTiles);
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

        cleanUp(display, event_queue, charEventQueue, images, charSelect, staticTiles);
    }
}
