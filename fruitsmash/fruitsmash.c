//2024.04.02.AE -> Original Version

//Author: Arnold Etta
//
//
//  fruitsmash.c
//  Fruit Smash Game
//
// This program contains the main function

#include "game_controller.h" // Includes globals.h, sprites.h and game_screen_files.h already
#include "nios2_ctrl_reg_macros.h"

struct fruit* GMBrd[BOARD_LENGTH][BOARD_WIDTH]; //Game Board (hopefully)

// 6 different types of Fruits. A maximum 8 of each fruit can appear on the Game Board.
struct fruit apple[8];
struct fruit orange[8];
struct fruit lemon[8];
struct fruit watermelon[8];
struct fruit blueberry[8];
struct fruit grape[8];

// 2 instantiated box selectors
struct box_selector sel_1;
struct box_selector sel_2;

// Game parameters declaration
int playerScore, targetScore, timeRemaining;

// Other assisting variables/structures declared
struct fruit* to_be_swapped_1;
struct fruit* to_be_swapped_2;
short int Buffer1[240][512]; // 240 rows, 512 (320 + padding) columns
short int Buffer2[240][512];


int main(void){
    // Initialize Variables and Data Structures
    for(int i = 0; i < 8; i++){
        apple[i] = initialize_fruit(0, 0, RED, apple_pic);
    }
    for(int i = 0; i < 8; i++){
        orange[i] = initialize_fruit(0, 0, ORANGE, orange_pic);
    }
    for(int i = 0; i < 8; i++){
        lemon[i] = initialize_fruit(0, 0, YELLOW, lemon_pic);
    }
    for(int i = 0; i < 8; i++){
        watermelon[i] = initialize_fruit(0, 0, GREEN, watermelon_pic);
    }
    for(int i = 0; i < 8; i++){
        blueberry[i] = initialize_fruit(0, 0, BLUE, blueberry_pic);
    }
    for(int i = 0; i < 8; i++){
        grape[i] = initialize_fruit(0, 0, PURPLE, grape_pic);
    }

    // Make each element in GMBrd point to a fruit structure 
    for(int col = 0; col < BOARD_WIDTH; col++){
        GMBrd[0][col] = &apple[col];
    }
    for(int col = 0; col < BOARD_WIDTH; col++){
        GMBrd[1][col] = &orange[col];
    }
    for(int col = 0; col < BOARD_WIDTH; col++){
        GMBrd[2][col] = &apple[col];
    }
    for(int col = 0; col < BOARD_WIDTH; col++){
        GMBrd[3][col] = &apple[col];
    }
    for(int col = 0; col < BOARD_WIDTH; col++){
        GMBrd[4][col] = &apple[col];
    }
    for(int col = 0; col < BOARD_WIDTH; col++){
        GMBrd[5][col] = &apple[col];
    }

    // Initialize box selectors
    sel_1 = initialize_box_selector();
    sel_2 = initialize_box_selector();
    

    // Setup Double Bufferring
    *(pixel_ctrl_ptr + 1) = (int) &Buffer1; // BackBuffer register holds address of Buffer1
    /* now, swap the front/back buffers, to set the front buffer location */
    wait_for_vsync();
    /* initialize a pointer to the pixel buffer, used by drawing functions */
    pixel_buffer_start = *pixel_ctrl_ptr; // pixel_buffer_start points to the contents in FrontBuffer register (Buffer1's address)
    draw_screen(start_screen);
    /* set current BackBuffer register to hold Buffer2's address */
    *(pixel_ctrl_ptr + 1) = (int) &Buffer2;
    pixel_buffer_start = *(pixel_ctrl_ptr + 1); // Point to new Back Buffer

    // Setup and Enable Nios II Interrupts
    /* set the interval timer period for scrolling the LED lights */
	int counter = 100000000; // 1/(100 MHz) x (100_000_000) = 1000 msec or 1sec
	*(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
	*(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;

    *(ps2_ptr + 1) = 0x1; // enable interrupts for PS/2 port

    /* set interrupt mask bits for levels 0 (interval timer) and level 7
	* (PS/2 port) */
	NIOS2_WRITE_IENABLE(0x81);
	NIOS2_WRITE_STATUS(1); // enable Nios II interrupts

    while(pause == 0){
        ; // wait for 'Enter' from user
    }

    initialize_GAME();
    wait_for_vsync();
    pixel_buffer_start = *(pixel_ctrl_ptr + 1);

    /* start interval timer, enable its interrupts */
	*(interval_timer_ptr + 1) = 0x7; // STOP = 0, START = 1, CONT = 1, ITO = 1

    while(1){
        if(pause == 1){
            *(interval_timer_ptr + 1) = 0xB; // STOP = 1, START = 0, CONT = 1, ITO = 1
            while(pause == 1){
                ;
            }
        }

        if(pause == 0){
            while(pause == 0){
                ; // wait for 'Enter' from user
            }

            initialize_GAME();
            wait_for_vsync();
            pixel_buffer_start = *(pixel_ctrl_ptr + 1);

            /* start interval timer, enable its interrupts */
            *(interval_timer_ptr + 1) = 0x7; // STOP = 0, START = 1, CONT = 1, ITO = 1
        }
    }
    
}