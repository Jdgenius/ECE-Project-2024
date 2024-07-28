//2024.04.02.AE -> Added possible arrangement arrays
//2024.03.31.AE -> Original Version

//Author: Arnold Etta


#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

    #include "sprites.h" // Includes globals.h
    #include "game_screen_files.h"

    struct box_selector{
        int x_loc, y_loc;

        bool isLatched; // Initialize to 0. Push to 1 when user presses enter to select a fruit
    };
    // Function to initialize a box_selector instance
    struct box_selector initialize_box_selector() {
        struct box_selector new_selector;
        new_selector.x_loc = 85;
        new_selector.y_loc = 30;
        new_selector.isLatched = false;
        return new_selector;
    };

    /*********************************************************************************************/
    /*                                  Function Declarations                                    */
    /*********************************************************************************************/
    void draw_box_selector(struct box_selector sel, bool clear);
    void draw_fruit(struct fruit* f0, int data_size);
    void draw_GMBrd(struct fruit* GMBrd[][BOARD_WIDTH]);
    void draw_target_score(int targer_score, bool clear);
    void draw_player_score(int player_score, bool clear);
    void draw_timer(int time, bool clear);
    void animate_box_selector(struct box_selector sel, int direction);
    void move_box_selector(int direction);
    /* IGNORE FOR NOW
    void animate_swap(char* swap[5], bool clear);
    void animate_menu(bool clear);
    void animate_squash(bool clear);
    */
    int check_match(struct fruit* GMBrd[][BOARD_WIDTH]);


    // Possible Game Board arrangements in 2D char type arrays
    char fruit_arrangement_1[6][8] = {
        {'R', 'O', 'Y', 'G', 'B', 'P', 'R', 'R'},
        {'B', 'G', 'R', 'P', 'Y', 'O', 'B', 'G'},
        {'P', 'B', 'Y', 'O', 'R', 'G', 'P', 'P'},
        {'R', 'R', 'O', 'Y', 'G', 'P', 'R', 'R'},
        {'Y', 'Y', 'B', 'R', 'O', 'G', 'Y', 'Y'},
        {'G', 'P', 'G', 'B', 'Y', 'R', 'G', 'G'}
    };


#endif