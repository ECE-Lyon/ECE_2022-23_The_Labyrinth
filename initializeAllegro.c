#include <stdio.h>
#include "initializeAllegro.h"
#include "struct_macro.h"

int coordX[3];
int coordY[3];
int coordx[BOARDSIZE][BOARDSIZE];
int coordy[BOARDSIZE][BOARDSIZE];


int initializeAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *Tiles[BOARDSIZE][BOARDSIZE]) {
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
    coordX[0] = 300;
    coordY[0] = 335;
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
    Tiles[0][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST1.jpg");
    coordSTx[0] = 250;
    coordSTy[0] = 183;
    Tiles[0][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST2.jpg");
    coordSTx[1] = 453;
    coordSTy[1] = 183;
    Tiles[0][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST3.jpg");
    coordSTx[2] = 656;
    coordSTy[2] = 183;
    Tiles[0][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST4.jpg");
    coordSTx[3] = 859;
    coordSTy[3] = 183;
    Tiles[2][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST5.jpg");
    coordSTx[4] = 250;
    coordSTy[4] = 386;
    Tiles[2][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST6.jpg");
    coordSTx[5] = 454;
    coordSTy[5] = 386;
    Tiles[2][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST7.jpg");
    coordSTx[6] = 657;
    coordSTy[6] = 386;
    Tiles[2][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST8.jpg");
    coordSTx[7] = 859;
    coordSTy[7] = 386;
    Tiles[4][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST9.jpg");
    coordSTx[8] = 250;
    coordSTy[8] = 589;
    Tiles[4][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST10.jpg");
    coordSTx[9] = 453;
    coordSTy[9] = 589;
    Tiles[4][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST11.jpg");
    coordSTx[10] = 656;
    coordSTy[10] = 589;
    Tiles[4][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST12.jpg");
    coordSTx[11] = 859;
    coordSTy[11] = 589;
    Tiles[6][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST13.jpg");
    coordSTx[12] = 250;
    coordSTy[12] = 792;
    Tiles[6][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST14.jpg");
    coordSTx[13] = 452;
    coordSTy[13] = 792;
    Tiles[6][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST15.jpg");
    coordSTx[14] = 656;
    coordSTy[14] = 792;
    Tiles[6][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST16.jpg");
    coordSTx[15] = 858;
    coordSTy[15] = 792;

    Tiles[0][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV1.jpg");
    coordMVx[0] = 352;
    coordMVy [0] = 183;
    Tiles[0][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV2.jpg");
    coordMVx[1] = 555;
    coordMVy [1] = 183;
    Tiles[0][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV3.jpg");
    coordMVx[2] = 758;
    coordMVy [2] = 183;
    Tiles[1][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV4.jpg");
    coordMVx[3] = 250;
    coordMVy [3] = 285;
    Tiles[1][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV5.jpg");
    coordMVx[4] = 352;
    coordMVy [4] = 285;
    Tiles[1][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV6.jpg");
    coordMVx[5] = 453;
    coordMVy [5] = 285;
    Tiles[1][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV34.jpg");
    coordMVx[6] = 555;
    coordMVy [6] = 285;
    Tiles[1][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV7.jpg");
    coordMVx[7] = 656;
    coordMVy [7] = 285;
    Tiles[1][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV8.jpg");
    coordMVx[8] = 758;
    coordMVy [8] = 285;
    Tiles[1][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV9.jpg");
    coordMVx[9] = 859;
    coordMVy [9] = 285;
    Tiles[2][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV10.jpg");
    coordMVx[10] = 352;
    coordMVy [10] = 386;
    Tiles[2][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV12.jpg");
    coordMVx[11] = 555;
    coordMVy [11] = 386;
    Tiles[2][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV13.jpg");
    coordMVx[12] = 758;
    coordMVy [12] = 386;
    Tiles[3][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV14.jpg");
    coordMVx[13] = 250;
    coordMVy [13] = 488;
    Tiles[3][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV15.jpg");
    coordMVx[14] = 352;
    coordMVy [14] = 488;
    Tiles[3][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV16.jpg");
    coordMVx[15] = 453;
    coordMVy [15] = 488;
    Tiles[3][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV17.jpg");
    coordMVx[16] = 555;
    coordMVy [16] = 488;
    Tiles[3][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV18.jpg");
    coordMVx[17] = 656;
    coordMVy [17] = 488;
    Tiles[3][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV19.jpg");
    coordMVx[18] = 758;
    coordMVy [18] = 488;
    Tiles[3][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV20.jpg");
    coordMVx[19] = 859;
    coordMVy [19] = 488;
    Tiles[4][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV21.jpg");
    coordMVx[20] = 352;
    coordMVy [20] = 589;
    Tiles[4][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV22.jpg");
    coordMVx[21] = 555;
    coordMVy [21] = 589;
    Tiles[4][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV23.jpg");
    coordMVx[22] = 758;
    coordMVy [22] = 589;
    Tiles[5][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV24.jpg");
    coordMVx[23] = 250;
    coordMVy [23] = 691;
    Tiles[5][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV25.jpg");
    coordMVx[24] = 352;
    coordMVy [24] = 691;
    Tiles[5][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV26.jpg");
    coordMVx[25] = 453;
    coordMVy [25] = 691;
    Tiles[5][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV27.jpg");
    coordMVx[26] = 555;
    coordMVy [26] = 691;
    Tiles[5][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV28.jpg");
    coordMVx[27] = 656;
    coordMVy [27] = 691;
    Tiles[5][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV29.jpg");
    coordMVx[28] = 758;
    coordMVy [28] = 691;
    Tiles[5][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV30.jpg");
    coordMVx[29] = 859;
    coordMVy [29] = 691;
    Tiles[6][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV31.jpg");
    coordMVx[30] = 352;
    coordMVy [30] = 792;
    Tiles[6][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV32.jpg");
    coordMVx[31] = 555;
    coordMVy [31] = 792;
    Tiles[6][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV33.jpg");
    coordMVx[32] = 758;
    coordMVy [32] = 792;


    // Register event sources for the queue
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    return event_queue;
}


int screenUpdate(int current_screen, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *Tiles[BOARDSIZE][BOARDSIZE], int current_char, int first) {
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
        al_draw_bitmap(images[current_screen], 0, 0, 0);
        int k = 0;
        for (int i = 0; i < BOARDSIZE; i++) {
            for (int j = 0; j < BOARDSIZE; j++) {
                al_draw_bitmap(Tiles[i][j], coordSTx[i], coordSTy[i], 0);
            }
            if(first == 1) {
                al_rest(0.07); //set to 0.07 in order to skip the THREE-TIMES-DISPLAY bug (usually 0.5s)
                al_flip_display();
            }
        }
    }
    else {
        al_draw_bitmap(images[current_screen], 0, 0, 0);
    }

    al_flip_display();
    return 0;
}


int cleanUp(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *Tiles[BOARDSIZE][BOARDSIZE]) {
for (int i = 0; i < NB_IMAGES; i++) al_destroy_bitmap(images[i]);
    for (int i = 0; i < 4; i++) al_destroy_bitmap(charSelect[i]);
    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {al_destroy_bitmap(Tiles[i][j]);}
    }
    al_destroy_event_queue(event_queue);
    //al_destroy_event_queue(charEventQueue);
    al_destroy_display(display);

    return 0;
}
