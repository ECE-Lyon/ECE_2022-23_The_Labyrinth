#include <stdio.h>
#include <string.h>
#include "round.h"

Case tempValue = {0};

int horizontal = 0, vertical = 0;
int choiceLine = 0;
int choice = 0;
int choiceWay = 0;

int checkWall(Case board[BOARDSIZE][BOARDSIZE], Pawn character, int arrow){
    int check = 0;
    if(strcmp(board[character.x][character.y].boxtype, "T") == 1) {
        if(board[character.x][character.y].boxway == 0) {
            if(arrow == 1) {
                check = 0;
            }
            else {
                check = 1;
            }
        }
        else if(board[character.x][character.y].boxway == 1){
            if(arrow == 3) {
                check = 0;
            }
            else {
                check = 1;
            }
        }
        else if(board[character.x][character.y].boxway == 2) {
            if(arrow == 2) {
                check = 0;
            }
            else {
                check = 1;
            }
        }
        else if(board[character.x][character.y].boxway == 3){
            if(arrow == 4) {
                check = 0;
            }
            else {
                check = 1;
            }
        }
        else {
            goto error;
        }
    }
    else if(strcmp(board[character.x][character.y].boxtype, "L") == 1) {
        if(board[character.x][character.y].boxway == 0) {
            if((arrow == 1) || (arrow == 3)) {
                check = 1;
            }
            else {
                check = 0;
            }
        }
        else if(board[character.x][character.y].boxway == 1){
            if((arrow == 3) || (arrow == 2)) {
                check = 1;
            }
            else {
                check = 0;
            }
        }
        else if(board[character.x][character.y].boxway == 2) {
            if((arrow == 2) || (arrow == 4)) {
                check = 1;
            }
            else {
                check = 0;
            }
        }
        else if(board[character.x][character.y].boxway == 3){
            if((arrow == 4) || (arrow == 1)) {
                check = 1;
            }
            else {
                check = 0;
            }
        }
        else {
            goto error;
        }
    }
    else if(strcmp(board[character.x][character.y].boxtype, "I") == 1) {
        if(board[character.x][character.y].boxway == 0) {
            if((arrow == 1) || (arrow == 2)) {
                check = 1;
            }
            else {
                check = 0;
            }
        }
        else if(board[character.x][character.y].boxway == 1){
            if((arrow == 3) || (arrow == 4)) {
                check = 1;
            }
            else {
                check = 0;
            }
        }
        else {
            goto error;
        }
    }
    else {
        goto error;
    }
    return check;

    error:
    printf("ERROR");
}


int oneRound(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_BITMAP *images[NB_IMAGES], ALLEGRO_BITMAP *charSelect[4], ALLEGRO_BITMAP *staticTiles[16], ALLEGRO_BITMAP *movableTiles[33], Case board[BOARDSIZE][BOARDSIZE], Case substituteValue, Pawn character, char treasureCardCharacter[NB_CARD_BY_PERSON][MAX_LETTERS_WORDS]) {

    //----MOVE ROW / COLUMN----//
    printf("\nThe extra piece is type %s\n", substituteValue.boxtype);

    //on ne demand pas dans quel sens on veut mettre la extra piece

    printf("\nDo you want to move a row(1) or a column(2) ? \n");
    scanf("%d", &choice);
    printf("Which row/column do you want to replace ? (2, 4 or 6)\n");
    scanf("%d", &choiceLine);
    while(!((choiceLine == 1 + 1) || (choiceLine == 3 + 1) || (choiceLine == 5 + 1))) {
        printf("You can't move the row/column, only 2, 4 and 6 are available. Which row/column do you want to replace ? \n");
        scanf("%d", &choiceLine);
    }
    printf("Do you want to move to the right/down(1), or to the left/up(2) ? \n");
    scanf("%d", &choiceWay);

    if(choiceWay == 1) {
        if (choice == 1) {
            tempValue = board[BOARDSIZE - 1][choiceLine - 1];
            for (vertical = BOARDSIZE - 1; vertical > 0; vertical--) {
                board[vertical][choiceLine - 1] = board[vertical - 1][choiceLine - 1];
            }
            board[0][choiceLine - 1] = substituteValue;
            substituteValue = tempValue;
        }
        else if (choice == 2) {
            tempValue = board[choiceLine - 1][BOARDSIZE - 1];
            for (horizontal = BOARDSIZE - 1; horizontal > 0; horizontal--) {
                board[choiceLine - 1][horizontal] = board[choiceLine - 1][horizontal - 1];
            }
            board[choiceLine - 1][0] = substituteValue;
            substituteValue = tempValue;
        }
    }

    else if(choiceWay == 2) {
        if (choice == 1) {
            tempValue = board[0][choiceLine - 1];
            for (vertical = 0; vertical < BOARDSIZE - 1; vertical++) {
                board[vertical][choiceLine - 1] = board[vertical + 1][choiceLine - 1];
            }
            board[BOARDSIZE - 1][choiceLine - 1]= substituteValue;
            substituteValue = tempValue;
        }
        else if (choice == 2) {
            tempValue = board[choiceLine - 1][0];
            for (horizontal = 0; horizontal < BOARDSIZE - 1; horizontal++) {
                board[choiceLine - 1][horizontal] = board[choiceLine - 1][horizontal + 1];
            }
            board[choiceLine - 1][BOARDSIZE - 1] = substituteValue;
            substituteValue = tempValue;
        }
    }


    //----MOVE PAWN----//
    printf("\nMove your pawn with the arrows of the keyboard, and press enter when you have finished your move \n");

    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    while((event.type == ALLEGRO_EVENT_KEY_DOWN) && (event.keyboard.keycode == ALLEGRO_KEY_ENTER)) {
        int arrow;
        printBoard(board);
        if((event.type == ALLEGRO_EVENT_KEY_DOWN) && (event.keyboard.keycode == ALLEGRO_KEY_UP)) {
            arrow = 1;
            int check = checkWall(board, character, arrow);
            if(check == 1) {
                character.y -= 1;
            }
            else {
                printf("Impossible to go top\n");
            }
        }
        if((event.type == ALLEGRO_EVENT_KEY_DOWN) && (event.keyboard.keycode == ALLEGRO_KEY_DOWN)) {
            arrow = 2;
            int check = checkWall(board, character, arrow);
            if(check == 1) {
                character.y += 1;
            }
            else {
                printf("Impossible to go down\n");
            }
        }
        if((event.type == ALLEGRO_EVENT_KEY_DOWN) && (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)) {
            arrow = 3;
            int check = checkWall(board, character, arrow);
            if(check == 1) {
                character.x += 1;
            }
            else {
                printf("Impossible to go right\n");
            }
        }
        if((event.type == ALLEGRO_EVENT_KEY_DOWN) && (event.keyboard.keycode == ALLEGRO_KEY_LEFT)) {
            arrow = 4;
            int check = checkWall(board, character, arrow);
            if(check == 1) {
                character.x -= 1;
            }
            else {
                printf("Impossible to go left\n");
            }
        }
    }


    //----TREASURE----//
    if(treasureCardCharacter[character.treasure] == board[character.x][character.y].treasure) {
        printf("Your have won the treasure you were looking for \n");
        character.treasure += 1;
        if(character.treasure == NB_TREASURE_CARD) {
            printf("You have won all the treasures you were looking for, now return to your starting point to win \n");
        }
        else {
            printf("Now, you are looking for %s\n", treasureCardCharacter[character.treasure]);
        }
    }

    return 0;
}
