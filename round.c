#include <stdio.h>
#include <string.h>
#include "round.h"

Case tempValue = {0};


int checkBorder(Pawn **character, int check) {
    if((character->y < 0) || (character->y > BOARDSIZE - 1) || (character->x < 0) || character->x > BOARDSIZE - 1) {
        check = 1;
    }
    return check;
}


int checkWall(Case board[BOARDSIZE][BOARDSIZE], Pawn *character, int arrow) {
    int check;
    checkBorder(&character, check);
    if(check == 0) {
        if (strcmp(board[character->y][character->x].boxtype, "T") == 1) {
            if (board[character->y][character->x].boxway == 0) {
                if (arrow == 1) {
                    check = 0;
                } else {
                    check = 1;
                }
            } else if (board[character->y][character->x].boxway == 1) {
                if (arrow == 3) {
                    check = 0;
                } else {
                    check = 1;
                }
            } else if (board[character->y][character->x].boxway == 2) {
                if (arrow == 2) {
                    check = 0;
                } else {
                    check = 1;
                }
            } else if (board[character->y][character->x].boxway == 3) {
                if (arrow == 4) {
                    check = 0;
                } else {
                    check = 1;
                }
            } else {
                goto error;
            }
        }
        else if (strcmp(board[character->y][character->x].boxtype, "L") == 1) {
            if (board[character->x][character->y].boxway == 0) {
                if ((arrow == 1) || (arrow == 3)) {
                    check = 1;
                } else {
                    check = 0;
                }
            } else if (board[character->y][character->x].boxway == 1) {
                if ((arrow == 3) || (arrow == 2)) {
                    check = 1;
                } else {
                    check = 0;
                }
            } else if (board[character->y][character->x].boxway == 2) {
                if ((arrow == 2) || (arrow == 4)) {
                    check = 1;
                } else {
                    check = 0;
                }
            } else if (board[character->y][character->x].boxway == 3) {
                if ((arrow == 4) || (arrow == 1)) {
                    check = 1;
                } else {
                    check = 0;
                }
            } else {
                goto error;
            }
        }
        else if (strcmp(board[character->y][character->x].boxtype, "I") == 1) {
            if (board[character->x][character->y].boxway == 0) {
                if ((arrow == 1) || (arrow == 2)) {
                    check = 1;
                } else {
                    check = 0;
                }
            } else if (board[character->y][character->x].boxway == 1) {
                if ((arrow == 3) || (arrow == 4)) {
                    check = 1;
                } else {
                    check = 0;
                }
            } else {
                goto error;
            }
        } else {
            goto error;
        }
    }
    return check;

    error:
        printf("ERROR");
        return 0;
}

//check if character on the substitute value


int oneRound(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33], Case board[BOARDSIZE][BOARDSIZE], Case *substituteValue, Pawn *character, char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS]) {

    //----MOVE ROW / COLUMN----//
    printf("\nThe extra piece is type %s\n", substituteValue->boxtype);

    //ask the way for the extra piece

    int choice = 0;
    printf("\nChoose the emplacement of the extra pieces (1 -> 12)\n");
    while(choice == 0) {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_A :
                    choice = 1;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_B :
                    choice = 2;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_C :
                    choice = 3;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_D :
                    choice = 4;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_E :
                    choice = 5;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_F :
                    choice = 6;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_G :
                    choice = 7;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_H :
                    choice = 8;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_I :
                    choice = 9;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_J :
                    choice = 10;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_K :
                    choice = 11;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_L :
                    choice = 12;
                    printf("%d", choice);
                    break;
                case ALLEGRO_KEY_M :
                    goto returnMainMenu;
                case ALLEGRO_KEY_TAB :
                    return 0;
            }
        }
    }

    if(choice < 7) {
        if (choice < 4) {
            tempValue = board[(choice * 2) - 1][BOARDSIZE - 1];
            for (int horizontal = BOARDSIZE - 1; horizontal > 0; horizontal--) {
                board[(choice * 2) - 1][horizontal] = board[(choice * 2) - 1][horizontal - 1];
            }
            board[(choice * 2) - 1][0] = *substituteValue;
            *substituteValue = tempValue;
        }
        else if (choice > 3) {
            tempValue = board[BOARDSIZE - 1][((choice - 3) * 2) - 1];
            for (int vertical = BOARDSIZE - 1; vertical > 0; vertical--) {
                board[vertical][((choice - 3) * 2) - 1] = board[vertical - 1][((choice - 3) * 2) - 1];
            }
            board[0][((choice - 3) * 2) - 1] = *substituteValue;
            *substituteValue = tempValue;
        }
    }

    else if(choice > 6) {
        if (choice < 10) {
            tempValue = board[((choice - 6) * 2) - 1][0];
            for (int horizontal = 0; horizontal < BOARDSIZE - 1; horizontal++) {
                board[((choice - 6) * 2) - 1][horizontal] = board[((choice - 6) * 2) - 1][horizontal + 1];
            }
            board[((choice - 6) * 2) - 1][BOARDSIZE - 1] = *substituteValue;
            *substituteValue = tempValue;
        }
        else if (choice > 9) {
            tempValue = board[0][((choice - 9) * 2) - 1];
            for (int vertical = 0; vertical < BOARDSIZE - 1; vertical++) {
                board[vertical][((choice - 9) * 2) - 1] = board[vertical + 1][((choice - 9) * 2) - 1];
            }
            board[BOARDSIZE - 1][((choice - 9) * 2) - 1]= *substituteValue;
            *substituteValue = tempValue;
        }
    }

    printBoard(board);

    //----MOVE PAWN----//
    printf("\nMove your pawn with the arrows of the keyboard, and press enter when you have finished your move \n");


    int k = 0;
    while(k == 0) {
        int arrow;

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if(event.keyboard.keycode == ALLEGRO_KEY_UP) {
                arrow = 1;
                int check = checkWall(board, &character, arrow);
                if (check == 1) {
                    character->x -= 1;
                    printBoard(board);
                } else {
                    printf("Impossible to go top\n");
                }
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                arrow = 2;
                int check = checkWall(board, &character, arrow);
                if (check == 1) {
                    character->x += 1;
                    printBoard(board);
                } else {
                    printf("Impossible to go down\n");
                }
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                arrow = 3;
                int check = checkWall(board, &character, arrow);
                if (check == 1) {
                    character->y += 1;
                    printBoard(board);
                } else {
                    printf("Impossible to go right\n");
                }
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                arrow = 4;
                int check = checkWall(board, &character, arrow);
                if (check == 1) {
                    character->y -= 1;
                    printBoard(board);
                } else {
                    printf("Impossible to go left\n");
                }
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                k = 1;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_M) {
                goto returnMainMenu;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_TAB) {
                return 0;
            }
        }
    }


    //----TREASURE----//
    if(treasureCardCharacter[character->treasure] == board[character->x][character->y].treasure) {
        printf("Your have won the treasure you were looking for \n");
        character->treasure += 1;
        if(character->treasure == NB_TREASURE_CARD) {
            printf("You have won all the treasures you were looking for, now return to your starting point to win \n");
        }
        else {
            printf("Now, you are looking for %s\n", treasureCardCharacter[character->treasure]);
        }
    }

    return 0;

    returnMainMenu:
        printf("\nERROR\n");
        al_rest(2.2);
        return 0;
}
