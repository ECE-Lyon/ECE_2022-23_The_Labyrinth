#include <stdio.h>
#include "initializeAllegro.h"
#include "struct_macro.h"

int coordX[3];
int coordY[3];
int coordSTx[16];
int coordSTy[16];
int coordMVx[33];
int coordMVy[33];


int initializeAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33]) {
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


    // Create event queue for the menu
    event_queue = al_create_event_queue();


    // Load the images
    images[0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/1.png");
    images[1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/2.png");
    images[2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/3.png");
    images[3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/4.png");
    images[4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/16.png");
    images[5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/17.png");
    images[6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/20.png");
    images[7] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/21.png");
    images[8] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/22.png");
    images[9] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BOARDblank.png");
    for (int i = 0; i < NB_IMAGES; i++) {
        if (images[i] == NULL) {
            printf("Error occured while loading image %d \n", i);
        }
    }


    //Load the images needed for the character selection screen as well as their coordinates
    charSelect[0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/BnWEMPERESS.png");
    coordX[0] = 297;
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
    staticTiles[0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST1.jpg");
    coordSTx[0] = 250;
    coordSTy[0] = 183;
    staticTiles[1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST2.jpg");
    coordSTx[1] = 453;
    coordSTy[1] = 183;
    staticTiles[2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST3.jpg");
    coordSTx[2] = 656;
    coordSTy[2] = 183;
    staticTiles[3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST4.jpg");
    coordSTx[3] = 859;
    coordSTy[3] = 183;
    staticTiles[4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST5.jpg");
    coordSTx[4] = 250;
    coordSTy[4] = 386;
    staticTiles[5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST6.jpg");
    coordSTx[5] = 454;
    coordSTy[5] = 386;
    staticTiles[6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST7.jpg");
    coordSTx[6] = 657;
    coordSTy[6] = 386;
    staticTiles[7] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST8.jpg");
    coordSTx[7] = 859;
    coordSTy[7] = 386;
    staticTiles[8] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST9.jpg");
    coordSTx[8] = 250;
    coordSTy[8] = 589;
    staticTiles[9] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST10.jpg");
    coordSTx[9] = 453;
    coordSTy[9] = 589;
    staticTiles[10] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST11.jpg");
    coordSTx[10] = 656;
    coordSTy[10] = 589;
    staticTiles[11] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST12.jpg");
    coordSTx[11] = 859;
    coordSTy[11] = 589;
    staticTiles[12] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST13.jpg");
    coordSTx[12] = 250;
    coordSTy[12] = 792;
    staticTiles[13] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST14.jpg");
    coordSTx[13] = 452;
    coordSTy[13] = 792;
    staticTiles[14] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST15.jpg");
    coordSTx[14] = 656;
    coordSTy[14] = 792;
    staticTiles[15] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST16.jpg");
    coordSTx[15] = 858;
    coordSTy[15] = 792;

    movableTiles[0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV1.jpg");
    coordMVx[0] = 352;
    coordMVy [0] = 183;
    movableTiles[1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV2.jpg");
    coordMVx[1] = 555;
    coordMVy [1] = 183;
    movableTiles[2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV3.jpg");
    coordMVx[2] = 758;
    coordMVy [2] = 183;
    movableTiles[3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV4.jpg");
    coordMVx[3] = 250;
    coordMVy [3] = 285;
    movableTiles[4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV5.jpg");
    coordMVx[4] = 352;
    coordMVy [4] = 285;
    movableTiles[5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV6.jpg");
    coordMVx[5] = 453;
    coordMVy [5] = 285;
    movableTiles[6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV6.jpg");
    coordMVx[6] = 555;
    coordMVy [6] = 285;
    movableTiles[7] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV7.jpg");
    coordMVx[7] = 656;
    coordMVy [7] = 285;
    movableTiles[8] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV8.jpg");
    coordMVx[8] = 758;
    coordMVy [8] = 285;
    movableTiles[9] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV9.jpg");
    coordMVx[9] = 859;
    coordMVy [9] = 285;
    movableTiles[10] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV10.jpg");
    coordMVx[10] = 352;
    coordMVy [10] = 386;
    movableTiles[11] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV12.jpg");
    coordMVx[11] = 555;
    coordMVy [11] = 386;
    movableTiles[12] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV13.jpg");
    coordMVx[12] = 758;
    coordMVy [12] = 386;
    movableTiles[13] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV14.jpg");
    coordMVx[13] = 250;
    coordMVy [13] = 488;
    movableTiles[14] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV15.jpg");
    coordMVx[14] = 352;
    coordMVy [14] = 488;
    movableTiles[15] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV16.jpg");
    coordMVx[15] = 453;
    coordMVy [15] = 488;
    movableTiles[16] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV17.jpg");
    coordMVx[16] = 555;
    coordMVy [16] = 488;
    movableTiles[17] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV18.jpg");
    coordMVx[17] = 656;
    coordMVy [17] = 488;
    movableTiles[18] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV19.jpg");
    coordMVx[18] = 758;
    coordMVy [18] = 488;
    movableTiles[19] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV20.jpg");
    coordMVx[19] = 859;
    coordMVy [19] = 488;
    movableTiles[20] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV21.jpg");
    coordMVx[20] = 352;
    coordMVy [20] = 589;
    movableTiles[21] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV22.jpg");
    coordMVx[21] = 555;
    coordMVy [21] = 589;
    movableTiles[22] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV23.jpg");
    coordMVx[22] = 758;
    coordMVy [22] = 589;
    movableTiles[23] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV24.jpg");
    coordMVx[23] = 250;
    coordMVy [23] = 691;
    movableTiles[24] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV25.jpg");
    coordMVx[24] = 352;
    coordMVy [24] = 691;
    movableTiles[25] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV26.jpg");
    coordMVx[25] = 453;
    coordMVy [25] = 691;
    movableTiles[26] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV27.jpg");
    coordMVx[26] = 555;
    coordMVy [26] = 691;
    movableTiles[27] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV28.jpg");
    coordMVx[27] = 656;
    coordMVy [27] = 691;
    movableTiles[28] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV29.jpg");
    coordMVx[28] = 758;
    coordMVy [28] = 691;
    movableTiles[29] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV30.jpg");
    coordMVx[29] = 859;
    coordMVy [29] = 691;
    movableTiles[30] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV31.jpg");
    coordMVx[30] = 352;
    coordMVy [30] = 792;
    movableTiles[31] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV32.jpg");
    coordMVx[31] = 555;
    coordMVy [31] = 792;
    movableTiles[32] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV33.jpg");
    coordMVx[32] = 758;
    coordMVy [32] = 792;


    // Register event sources for the queue
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    return event_queue;
}


int screenUpdate(int current_screen, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33], int current_char, int first) {
    // Ensure the current index is within bounds
    if (current_screen < 0) current_screen = 0;
    if (current_screen >= NB_IMAGES) current_screen = NB_IMAGES - 1;

    // Render the current image
    // check if a character is being selected, and grey it if so
    if (current_screen == 4) {
        if(first == 1) {
            al_draw_bitmap(images[current_screen], 0, 0, 0);
        }
        else {
            al_draw_bitmap(charSelect[current_char], coordX[current_char], coordY[current_char], 0);
        }
    }
    else if (current_screen == 9) {
        if(first == 1) {
            al_draw_bitmap(images[current_screen], 0, 0, 0);
        }
        for (int i = 0; i < NB_ST_TILES; i++) {
            al_draw_bitmap(staticTiles[i], coordSTx[i], coordSTy[i], 0);
            al_rest(0.07); //set to 0.07 in order to skip the THREE-TIMES-DISPLAY bug (usually 0.5s)
            al_flip_display();
            if (i == 15) {
                break;
            }
            printf("boucle x%d\n", i);
        }
        for (int i = 0; i < NB_MV_TILES; i++) {
            al_draw_bitmap(movableTiles[i], coordMVx[i], coordMVy[i], 0);
            al_rest(0.07); //set to 0.07 in order to skip the THREE-TIMES-DISPLAY bug (usually 0.5s)
            al_flip_display();
        }
        printf("full bitmap drawn x time\n");
    }
    else {
        al_draw_bitmap(images[current_screen], 0, 0, 0);
    }

    al_flip_display();
    return 0;
}


int cleanUp(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33]) {
for (int i = 0; i < NB_IMAGES; i++) al_destroy_bitmap(images[i]);
    for (int i = 0; i < 4; i++) al_destroy_bitmap(charSelect[i]);
    for (int i = 0; i < 16; i++) al_destroy_bitmap(staticTiles[i]);
    for (int i = 0; i < 33; i++) al_destroy_bitmap(movableTiles[i]);
    al_destroy_event_queue(event_queue);
    //al_destroy_event_queue(charEventQueue);
    al_destroy_display(display);

    return 0;
}