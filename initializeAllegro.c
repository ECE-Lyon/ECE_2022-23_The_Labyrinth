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
    coordx[0][0] = 250;
    coordy[0][0] = 183;
    Tiles[0][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST2.jpg");
    coordx[0][2] = 453;
    coordy[0][2] = 183;
    Tiles[0][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST3.jpg");
    coordx[0][4] = 656;
    coordy[0][4] = 183;
    Tiles[0][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST4.jpg");
    coordx[0][6] = 859;
    coordy[0][6] = 183;
    Tiles[2][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST5.jpg");
    coordx[2][0] = 250;
    coordy[2][0] = 386;
    Tiles[2][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST6.jpg");
    coordx[2][2] = 454;
    coordy[2][2] = 386;
    Tiles[2][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST7.jpg");
    coordx[2][4] = 657;
    coordy[2][4] = 386;
    Tiles[2][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST8.jpg");
    coordx[2][6] = 859;
    coordy[2][6] = 386;
    Tiles[4][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST9.jpg");
    coordx[4][0] = 250;
    coordy[4][0] = 589;
    Tiles[4][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST10.jpg");
    coordx[4][2] = 453;
    coordy[4][2] = 589;
    Tiles[4][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST11.jpg");
    coordx[4][4] = 656;
    coordy[4][4] = 589;
    Tiles[4][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST12.jpg");
    coordx[4][6] = 859;
    coordy[4][6] = 589;
    Tiles[6][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST13.jpg");
    coordx[6][0] = 250;
    coordy[6][0] = 792;
    Tiles[6][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST14.jpg");
    coordx[6][2] = 452;
    coordy[6][2] = 792;
    Tiles[6][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST15.jpg");
    coordx[6][4] = 656;
    coordy[6][4] = 792;
    Tiles[6][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/tst/ST16.jpg");
    coordx[6][6] = 858;
    coordy[6][6] = 792;


    Tiles[0][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV1.jpg");
    coordx[0][1] = 352;
    coordy[0][1] = 183;
    Tiles[0][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV2.jpg");
    coordx[0][3] = 555;
    coordy[0][3] = 183;
    Tiles[0][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV3.jpg");
    coordx[0][5] = 758;
    coordy[0][5] = 183;
    Tiles[1][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV4.jpg");
    coordx[1][0] = 250;
    coordy[1][0] = 285;
    Tiles[1][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV5.jpg");
    coordx[1][1] = 352;
    coordy[1][1] = 285;
    Tiles[1][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV6.jpg");
    coordx[1][2] = 453;
    coordy[1][2] = 285;
    Tiles[1][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV34.jpg");
    coordx[1][3] = 555;
    coordy[1][3] = 285;
    Tiles[1][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV7.jpg");
    coordx[1][4] = 656;
    coordy[1][4] = 285;
    Tiles[1][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV8.jpg");
    coordx[1][5] = 758;
    coordy[1][5] = 285;
    Tiles[1][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV9.jpg");
    coordx[1][6] = 859;
    coordy[1][6] = 285;
    Tiles[2][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV10.jpg");
    coordx[2][1] = 352;
    coordy[2][1] = 386;
    Tiles[2][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV12.jpg");
    coordx[2][3] = 555;
    coordy[2][3] = 386;
    Tiles[2][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV13.jpg");
    coordx[2][5] = 758;
    coordy[2][5] = 386;
    Tiles[3][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV14.jpg");
    coordx[3][0] = 250;
    coordy[3][0] = 488;
    Tiles[3][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV15.jpg");
    coordx[3][1] = 352;
    coordy[3][1] = 488;
    Tiles[3][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV16.jpg");
    coordx[3][2] = 453;
    coordy[3][2] = 488;
    Tiles[3][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV17.jpg");
    coordx[3][3] = 555;
    coordy[3][3] = 488;
    Tiles[3][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV18.jpg");
    coordx[3][4] = 656;
    coordy[3][4] = 488;
    Tiles[3][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV19.jpg");
    coordx[3][5] = 758;
    coordy[3][5] = 488;
    Tiles[3][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV20.jpg");
    coordx[3][6] = 859;
    coordy[3][6] = 488;
    Tiles[4][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV21.jpg");
    coordx[4][1] = 352;
    coordy[4][1] = 589;
    Tiles[4][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV22.jpg");
    coordx[4][3] = 555;
    coordy[4][3] = 589;
    Tiles[4][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV23.jpg");
    coordx[4][5] = 758;
    coordy[4][5] = 589;
    Tiles[5][0] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV24.jpg");
    coordx[5][0] = 250;
    coordy[5][0] = 691;
    Tiles[5][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV25.jpg");
    coordx[5][1] = 352;
    coordy[5][1] = 691;
    Tiles[5][2] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV26.jpg");
    coordx[5][2] = 453;
    coordy[5][2] = 691;
    Tiles[5][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV27.jpg");
    coordx[5][3] = 555;
    coordy[5][3] = 691;
    Tiles[5][4] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV28.jpg");
    coordx[5][4] = 656;
    coordy[5][4] = 691;
    Tiles[5][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV29.jpg");
    coordx[5][5] = 758;
    coordy[5][5] = 691;
    Tiles[5][6] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV30.jpg");
    coordx[5][6] = 859;
    coordy[5][6] = 691;
    Tiles[6][1] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV31.jpg");
    coordx[6][1] = 352;
    coordy[6][1] = 792;
    Tiles[6][3] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV32.jpg");
    coordx[6][3] = 555;
    coordy[6][3] = 792;
    Tiles[6][5] = al_load_bitmap("C:/Users/jadep/Downloads/ALLEGRO_LABYRINTH/mv/MV33.jpg");
    coordx[6][5] = 758;
    coordy[6][5] = 792;


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
                al_draw_bitmap(Tiles[i][j], coordx[i][j], coordy[i][j], 0);
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
