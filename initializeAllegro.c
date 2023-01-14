#include <stdio.h>
#include "initializeAllegro.h"

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT_QUEUE *charEventQueue = NULL;
ALLEGRO_BITMAP *images[NB_IMAGES];
ALLEGRO_BITMAP *charSelect[4]; //remettre 4 sinon
ALLEGRO_BITMAP *staticTiles[16];

int coordX[3];
int coordY[3];
int coordSTx[16];
int coordSTy[16];

int menu_flag = 0;
int current_index = 0;
int current_char = 0;
int current_X = 0;
int current_Y = 0;


void initializeAllegro() {

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
    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW | ALLEGRO_RESIZABLE | ALLEGRO_NOFRAME); //window specs
    al_set_window_title(display, "LABYRINTH: Extended version"); //window name
    al_set_window_position(display, x, y); // Set the window's position


    // Create two event queues for the menu and the character selection
    event_queue = al_create_event_queue();
    charEventQueue = al_create_event_queue();


    // Load the images
    images[0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/1.png");
    images[1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/2.png");
    images[2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/3.png");
    images[3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/4.png");
    images[4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/5.png");
    images[5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/6.png");
    images[6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/7.png");
    images[7] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/8.png");
    images[8] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/9.png");
    images[9] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/10.png");
    images[10] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/11.png");
    images[11] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/12.png");
    images[12] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/13.png");
    images[13] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/14.png");
    images[14] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/15.png");
    images[15] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/16.png");
    images[16] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/17.png");
    images[17] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/18.png");
    images[18] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/19.png");
    images[19] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/20.png");
    images[20] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/21.png");
    images[21] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BOARD0.png");
    images[22] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BOARDblank.png");
    for (int i = 0; i < NB_IMAGES; i++) {
        if (images[i] == NULL) {
            printf("Error occured while loading image %d \n", i);
        }
    }


    //Load the images needed for the character selection screen as well as their coordinates
    charSelect[0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BnWEMPERESS.png");
    coordX[0] = 0;
    coordY[0] = 331;
    charSelect[1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BnWARCHDRUID.png");
    coordX[1] = 653;
    coordY[1] = 325;
    charSelect[2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BnWSEER.png");
    coordX[2] = 1016;
    coordY[2] = 329;
    charSelect[3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BnWWANDERER.png");
    coordX[3] = 1374;
    coordY[3] = 290;


    //Load the images needed for the board initialization as well as their coordinates
    staticTiles[0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST1.jpg");
    coordSTx[0] = 250;
    coordSTy[0] = 183;
    staticTiles[1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST2.jpg");
    coordSTx[1] = 453;
    coordSTy[1] = 183;
    staticTiles[2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST3.jpg");
    coordSTx[2] = 656;
    coordSTy[2] = 183;
    staticTiles[3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST4.jpg");
    coordSTx[3] = 859;
    coordSTy[3] = 183;
    staticTiles[4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST5.jpg");
    coordSTx[4] = 250;
    coordSTy[4] = 386;
    staticTiles[5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST6.jpg");
    coordSTx[5] = 454;
    coordSTy[5] = 386;
    staticTiles[6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST7.jpg");
    coordSTx[6] = 657;
    coordSTy[6] = 386;
    staticTiles[7] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST8.jpg");
    coordSTx[7] = 859;
    coordSTy[7] = 386;
    staticTiles[8] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST9.jpg");
    coordSTx[8] = 250;
    coordSTy[8] = 589;
    staticTiles[9] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST10.jpg");
    coordSTx[9] = 453;
    coordSTy[9] = 589;
    staticTiles[10] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST11.jpg");
    coordSTx[10] = 656;
    coordSTy[10] = 589;
    staticTiles[11] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST12.jpg");
    coordSTx[11] = 859;
    coordSTy[11] = 589;
    staticTiles[12] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST13.jpg");
    coordSTx[12] = 250;
    coordSTy[12] = 792;
    staticTiles[13] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST14.jpg");
    coordSTx[13] = 452;
    coordSTy[13] = 792;
    staticTiles[14] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST15.jpg");
    coordSTx[14] = 656;
    coordSTy[14] = 792;
    staticTiles[15] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/ST16.jpg");
    coordSTx[15] = 858;
    coordSTy[15] = 792;


    // Register event sources for the two queues
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(charEventQueue, al_get_display_event_source(display));
    al_register_event_source(charEventQueue, al_get_keyboard_event_source());
}


void screenUpdate() {
    // Ensure the current index is within bounds
    if (current_index < 0) current_index = 0;
    if (current_index >= NB_IMAGES) current_index = NB_IMAGES - 1;

    // Render the current image
    al_draw_bitmap(images[current_index], 0, 0, 0);

    // check if a charcter is being selected, and grey it if so
    if (current_index == 15) {
        al_draw_bitmap(charSelect[current_char], coordX[current_X], coordY[current_Y], 0);
    }
    if (current_index == 22) {
        for (int i = 0; i < NB_ST_TILES; i++) {
            al_draw_bitmap(staticTiles[i], coordSTx[i], coordSTy[i], 0);
            al_rest(0.07); //set to 0.07 in order to skip the THREE-TIMES-DISPLAY bug (usually 0.5s)
            al_flip_display();
            if (i == 15) {
                printf("i reached 15"); //ici, un bug fait que l'affichage est performé 3 fois.. à régler
                break;
            }
        }
    }
    al_flip_display();
}

void cleanUp() {
    for (int i = 0; i < NB_IMAGES; i++) al_destroy_bitmap(images[i]);
    for (int i = 0; i < 4; i++) al_destroy_bitmap(charSelect[i]);
    for (int i = 0; i < 16; i++) al_destroy_bitmap(staticTiles[i]);
    al_destroy_event_queue(event_queue);
    al_destroy_event_queue(charEventQueue);
    al_destroy_display(display);
}