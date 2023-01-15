#include <stdio.h>
#include "initializeAllegro.h"
#include "startGame.h"


int main(void) {

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_BITMAP *images[NB_IMAGES];
    ALLEGRO_BITMAP *charSelect[4];
    ALLEGRO_BITMAP *staticTiles[16];
    ALLEGRO_BITMAP *movableTiles[33];


    event_queue = initializeAllegro(display, event_queue, images, charSelect, staticTiles, movableTiles);
    screenUpdate(0, images, charSelect,  staticTiles, movableTiles, 0, 0);

    while (1) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);


        // Check for events
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if(event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                screenUpdate(3, images, charSelect, staticTiles, movableTiles, 0, 0);
                startGame(display, event_queue, images, charSelect,  staticTiles, movableTiles);
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_M) {
                screenUpdate(0, images, charSelect,  staticTiles, movableTiles, 0, 0);
            }
            if((event.keyboard.keycode == ALLEGRO_KEY_A) || (event.keyboard.keycode == ALLEGRO_KEY_R)) {
                screenUpdate(1, images, charSelect,  staticTiles, movableTiles, 0, 0);
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_D) {
                screenUpdate(2, images, charSelect,  staticTiles, movableTiles, 0, 0);
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_TAB) {
                return 0;
            }
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
    }

    cleanUp(display, event_queue, images, charSelect, staticTiles, movableTiles);

    return 0;
}
